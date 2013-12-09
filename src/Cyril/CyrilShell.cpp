//
//  CyrilShell.cpp
//  cyril
//
//  Created by Darren Mothersele on 29/11/2013.
//
//

#include "CyrilShell.h"
#include "ShaderEvaluator.h"
#include "cyrilApp.h"

void CyrilShell::runCommand(string c) {
  if (strncmp("state", c.c_str(), 5) == 0) {
    printState();
  }
  else if (strncmp("shaders", c.c_str(), 7) == 0) {
    shader(c);
  }
  else if (strncmp("clear", c.c_str(), 5) == 0) {
    clear();
  }
  else if (strncmp("new", c.c_str(), 3) == 0) {
    newProg(c);
  }
  else if (c == "") {
    cout << endl;
  }
  else {
    cout << "[error] Unknown command" << endl;
  }
}

void CyrilShell::newProg(string _c) {
  if (_c.length() > 4) {
    string name = _c.substr(4, _c.length() - 4);
    if (ofFile::doesFileExist(name)) {
      ((cyrilApp *)ofGetAppPtr())->editor.addBuffer(new CyrilEvaluator(), "", name);
      int whichBuffer = ((cyrilApp *)ofGetAppPtr())->editor.numberOfBuffers - 1;
      ((cyrilApp *)ofGetAppPtr())->editor.loadFile(name, whichBuffer);
      cout << "Open new buffer for " << name << endl;
    }
    else {
      cout << "Error file not found " << name << endl;
    }
  }
  else {
    cout << "Incomplete command" << endl;
  }
  /*
  editor.addBuffer(new CyrilEvaluator(), "");
  editor.addBuffer(new CyrilEvaluator(), "");
  editor.addBuffer(new CyrilEvaluator(), "");
  editor.addBuffer(new CyrilEvaluator(), "");
  editor.addBuffer(new CyrilEvaluator(), "");*/
}

void CyrilShell::clear() {
  buffer->clear();
  buffer->appendShellEntry();
}

void CyrilShell::printState() {
  state->printState();
  //buffer->appendShellEntry();
}
void CyrilShell::shader(string c) {
  bool valid = false;
  // shaders
  if (c.length() == 7) {
    state->printShaders();
    valid = true;
  }
  // shaders edit frag 0
  if (c.length() > 18) {
    if (c.compare(8, 4, "edit") == 0) {
      int shaderType;
      if (c.compare(13,4,"frag") == 0) {
        //cout << "edit frag shader" << endl;
        shaderType = GL_FRAGMENT_SHADER;
        valid = true;
      }
      else if (c.compare(13, 4, "vert") == 0) {
        //cout << "edit vert shader" << endl;
        shaderType = GL_VERTEX_SHADER;
        valid = true;
      }
      if (valid == true && c.at(18) >= '0' && c.at(18) <= '9') {
        int shaderNo = c.at(18) - '0';
        if (state->shaders->count(shaderNo)) {
          //cout << "Edit shader " << shaderNo << endl;
          ((cyrilApp *)ofGetAppPtr())->editor.addBuffer(new ShaderEvaluator(shaderType, shaderNo), state->shaders->at(shaderNo)->getText(shaderType));
          cout << "Loaded new editor buffer with shader" << endl;
        }
        else {
          cout << "[error] shader not loaded" << endl;
          valid = false;
        }
      }
    }
  }
  if (!valid) {
    cout << "[error] incomplete shader command" << endl;
  }
}

/*
 
 // TODO: This is a test of a fragment shader editor
 ofFile file;
 // open file, read only, not binary
 file.open(ofToDataPath("shaders/noise.frag"), ofFile::ReadOnly, false);
 ofBuffer buf = file.readToBuffer();
 string shaderTxt = buf.getText();
 //cout << shaderTxt << endl;
 ShaderEvaluator *fragShader = new ShaderEvaluator(GL_FRAGMENT_SHADER, 0);
 
 // TODO: This is a test of a vertex shader editor
 file;
 // open file, read only, not binary
 file.open(ofToDataPath("shaders/noise.vert"), ofFile::ReadOnly, false);
 buf = file.readToBuffer();
 shaderTxt = buf.getText();
 //cout << shaderTxt << endl;
 ShaderEvaluator *vertShader = new ShaderEvaluator(GL_VERTEX_SHADER, 0);
 editor.addBuffer(vertShader, shaderTxt);
 */





