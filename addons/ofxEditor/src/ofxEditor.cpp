//
//  ofxEditor.cpp
//  textEditor
//
//  Created by Darren Mothersele on 19/11/2013.
//
//

#include "ofxEditor.h"

ofxEditor::ofxEditor(int noBuffers, string fontname) :
textColor(ofColor::white, 200),
textBorderColor(ofColor::white, 200),
cursorColor(ofColor::white, 200),
highlightColor(ofColor::white, 200)
{
  //cout << "Configure editor with " << noBuffers << " buffers" << endl;
  // Load font from "data/" folder
  //font.loadFont(fontname, 20, true, false, true, 0.00001);
  //font.loadFont(fontname, 5, true, false, true);
  font.loadFont(fontname, 20);

  // Reserve text buffers
  buf.reserve(noBuffers);
  for (int i = 0; i < noBuffers; ++i) {
    buf[i] = new EditorBuffer(&font);
    buf[i]->setTextColor(textColor, textBorderColor);
    buf[i]->setCursorColor(cursorColor);
    buf[i]->setHighlightColor(highlightColor);
  }
  currentBuffer = 1;
  maxBuffer = noBuffers - 1;

  // Create a frame buffer to render to
  ofFbo::Settings settings;
  settings.width = ofGetWidth();
  settings.height = ofGetHeight();
  editorFbo.allocate(settings);
  editorFbo.begin();
  ofClear(0,0,0,0);
  editorFbo.end();

  // Add listener for key events
  ofAddListener(ofEvents().keyPressed,this,&ofxEditor::handleKeyPress);
  // Add listener for window size event
  ofAddListener(ofEvents().windowResized,this,&ofxEditor::windowResized);

  update();
}


void ofxEditor::handleKeyPress(ofKeyEventArgs & _key) {

  int key = _key.key;
  bool alt   = (bool) (ofGetKeyPressed(OF_KEY_ALT));
  bool shift = (bool) (ofGetKeyPressed(OF_KEY_SHIFT));
  bool cmd   = (bool) (ofGetKeyPressed(OF_KEY_COMMAND));
  bool ctrl  = (bool) (ofGetKeyPressed(OF_KEY_CONTROL));

  // GLFW bug see issue: https://github.com/openframeworks/openFrameworks/issues/2562
  // Allow shift on non-alpha characters
  if (shift) {
    // 1 ! 49 33
    if (key == 49) key = 33;
    // 2 @ 50 64
    else if (key == 50) key = 64;
    // 3 £ 51 -- use # 35
    else if (key == 51) key = 35;
    // 4 $ 52 36
    else if (key == 52) key = 36;
    // 5 % 53 37
    else if (key == 53) key = 37;
    // 6 ^ 54 94
    else if (key == 54) key = 94;
    // 7 & 55 38
    else if (key == 55) key = 38;
    // 8 * 56 42
    else if (key == 56) key = 42;
    // 9 ( 57 40
    else if (key == 57) key = 40;
    // 0 ) 48 41
    else if (key == 48) key = 41;
    // - _ 45 95
    else if (key == 45) key = 95;
    // = + 61 43
    else if (key == 61) key = 43;
    // [ { 91 123
    else if (key == 91) key = 123;
    // ] } 93 125
    else if (key == 93) key = 125;
    // ; : 59 58
    else if (key == 59) key = 58;
    // ' " 39 34
    else if (key == 39) key = 34;
    // \ | 92 124
    else if (key == 92) key = 124;
    // ` ~ 96 126
    else if (key == 96) key = 126;
    // , < 44 60
    else if (key == 44) key = 60;
    // . > 46 62
    else if (key == 46) key = 62;
    // / ? 47 63
    else if (key == 47) key = 63;
  }


  // Add printable ASCII characters to buffer text
  if (!cmd && key < 127 && key > 31) {
    buf[currentBuffer]->insert(key);
  }
  // Add new line to buffer text
  if (key == 13) {
    buf[currentBuffer]->insert('\n');
  }
  // Pass backspace delete to text buffer
  if (key == 127) {
    buf[currentBuffer]->backspace();
  }
  // Pass clear command to text buffer
  if (cmd && key == 'n') {
    buf[currentBuffer]->clear();
  }

  // Move cursor around with arrow keys
  // up 357
  if (key == 357) {
    buf[currentBuffer]->moveCursorRow(-1, shift, cmd);
  }
  // down 359
  if (key == 359) {
    buf[currentBuffer]->moveCursorRow(1, shift, cmd);
  }
  // left 356
  if (key == 356) {
    buf[currentBuffer]->moveCursorCol(-1, shift, cmd);
  }
  // right 358
  if (key == 358) {
    buf[currentBuffer]->moveCursorCol(1, shift, cmd);
  }

  if (cmd && key == 'x') {
    ClipBoard::setText(buf[currentBuffer]->getSelection());
    buf[currentBuffer]->removeSelection();
  }
  if (cmd && key == 'c') {
    ClipBoard::setText(buf[currentBuffer]->getSelection());
  }
  if (cmd && key == 'v') {
    buf[currentBuffer]->insert(ClipBoard::getText());
  }

  // ESC key (27) handled elsewhere

  // Tab through buffers
  if (key == 9) {
    if (shift || cmd) {
      if (--currentBuffer < 0) currentBuffer = maxBuffer;
    }
    else {
      if (++currentBuffer > maxBuffer) currentBuffer = 0;
    }
    //cout << "Switch to buffer " << currentBuffer << " of " << maxBuffer << endl;
  }
  // Switch buffer using ALT+number
  if (cmd && key >= 49 && key <= 57) {
    int newBuffer = key - 48;
    if (newBuffer <= maxBuffer) {
      currentBuffer = newBuffer;
    }
  }
  // Extra buffer switch for 0
  if (cmd && key == 48) {
    if (9 <= maxBuffer) {
      currentBuffer = 0;
    }
  }

  if (cmd) {
    if (cmds.count(key) > 0) {
      pair<void *, EditorCommand> callback = cmds[key];
      (*callback.second)(callback.first);
    }
  }

  //cout << "Key pressed " << key << endl;

  // Key has been pressed so update the editor fbo
  update();
}


void ofxEditor::draw() {
  ofPushStyle();
  ofDisableLighting();
  ofSetColor(255, 255, 255, 255);
  editorFbo.draw(0, 0);
  ofPopStyle();
}


void ofxEditor::update() {
  ofPushStyle();
  editorFbo.begin();
  ofClear(0,0,0,0);
  
  //ofSetColor(255, 0, 0, 200);
  //ofRect(40,20,ofGetWidth() - 100, ofGetHeight() - 50);
  ofSetColor(255, 255, 255, 255);
  ofFill();
  buf[currentBuffer]->draw(40, 20, ofGetWidth() - 100, ofGetHeight() - 50);
  
  editorFbo.end();
  ofPopStyle();
}


void ofxEditor::windowResized(ofResizeEventArgs & resize) {
  ofFbo::Settings settings;
  settings.width = resize.width;
  settings.height = resize.height;
  editorFbo.allocate(settings);
  editorFbo.begin();
  ofClear(0,0,0,0);
  editorFbo.end();
}

bool ofxEditor::loadFile(string filename, int whichBuffer) {
  
  if (whichBuffer < 0 || whichBuffer > maxBuffer) return false;
  
	string path = ofToDataPath(filename);
	ofFile file;
	if(!file.open(ofToDataPath(path), ofFile::ReadOnly)){
		return false;
	}
  buf[whichBuffer]->setText(file.readToBuffer().getText());
	file.close();
	return true;
}
bool ofxEditor::saveFile(string filename, int whichBuffer) {
  
  if (whichBuffer < 0 || whichBuffer > maxBuffer) return false;
  
	string path = ofToDataPath(filename);
  
	ofFile file;
	if(!file.open(path, ofFile::WriteOnly)){
		return false;
	}
	
	file << buf[whichBuffer]->getText();
	file.close();
  
	return true;
}








