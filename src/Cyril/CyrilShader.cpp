//
//  CyrilShader.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilShader.h"
#include "CyrilState.h"

void CyrilShader::evalUniforms(int i, CyrilState *_s) {
  if (progU->valid) {
    (*_s->sym)[REG_CURRENT_SHADER] = float(i);
    progU->eval(*_s);
  }
}

string CyrilShader::getText(int _t) {
  if (_t == GL_VERTEX_SHADER) {
    return vert;
  }
  else if (_t == GL_FRAGMENT_SHADER) {
    return frag;
  }
  return "";
}

void CyrilShader::print() {
  cout << name;
  if (isLoaded()) {
    cout << " [loaded]";
  }
}

void CyrilShader::load(string _s1, string _s2) {
  ofFile file;
  file.open(ofToDataPath(_s1), ofFile::ReadOnly, false);
  ofBuffer buf = file.readToBuffer();
  vert = buf.getText();
  bool valid = ofShader::setupShaderFromSource(GL_VERTEX_SHADER, vert);
  if (valid) {
    file.open(ofToDataPath(_s2), ofFile::ReadOnly, false);
    buf = file.readToBuffer();
    frag = buf.getText();
    valid = ofShader::setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
    if (valid) {
      valid = linkProgram();
    }
  }
  if (!valid) {
    cout << "[error] error compiling and linking shaders" << endl;
  }
}

bool CyrilShader::setupShaderFromSource(GLenum type, string source) {
  bool valid = ofShader::setupShaderFromSource(type, source);
  if (valid) {
    switch (type) {
      case GL_VERTEX_SHADER:
        vert = source;
        valid = ofShader::setupShaderFromSource(GL_FRAGMENT_SHADER, frag);
        break;
      case GL_FRAGMENT_SHADER:
        frag = source;
        valid = ofShader::setupShaderFromSource(GL_VERTEX_SHADER, vert);
        break;
    }
    if (valid) {
      valid = linkProgram();
    }
  }
  cout << "[error] Error compiling and linking shaders" << endl;
  return valid;
}