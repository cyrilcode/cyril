//
//  ofxEditor.h
//  textEditor
//
//  Created by Darren Mothersele on 19/11/2013.
//
//

#ifndef __textEditor__ofxEditor__
#define __textEditor__ofxEditor__

#include "ofMain.h"
#include "ClipBoard.h"
#include "EditorBuffer.h"

typedef void (*EditorCommand)(void *);

class ofxEditor {

  ofFbo editorFbo;
  ofTrueTypeFont font;

  ofColor textColor;
  ofColor textBorderColor;
  ofColor cursorColor;
  ofColor highlightColor;

  map<int, pair<void *, EditorCommand> > cmds;

public:
  ofxEditor(int noBuffers = 1, string fontname = "DroidSansMono.ttf");

  void addCommand(int key, void *_o, EditorCommand _c) {
    cmds[key] = make_pair(_o, _c);
  }

  void handleKeyPress(ofKeyEventArgs &);

  void draw();
  void update();

  void windowResized(ofResizeEventArgs &);

  vector<EditorBuffer*> buf;
  int currentBuffer;
  int maxBuffer;
  
  bool loadFile(string filename, int whichBuffer);
  bool saveFile(string filename, int whichBuffer);
  
};


#endif /* defined(__textEditor__ofxEditor__) */
