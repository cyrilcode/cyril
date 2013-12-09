//
//  CyrilPalette.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "CyrilPalette.h"
#include "CyrilState.h"

CyrilPalette::CyrilPalette(int _l, Cyril* _p) : loc(_l) {
  int sz = _p->size();
  //cout << "Palette size " << sz << endl;
  if (sz % 4 != 0) {
    yyerror("Palette command formatted incorrectly");
    valid = false;
  }
  else if (!_p->valid) {
    valid = false;
  }
  else {
    palette = new Palette();
    CyrilState _state;
    _state.stk = new stack<float>;
    _state.ms = new ofMatrixStack(*ofGetWindowPtr());
    _state.ps = new vector<Particle*>;
    _state.sym = new map<int, float>;
    _state.cs = new map<int, Palette *>;
    _state.img = new map<int, ofImage *>;
    _state.parent = NULL;
    
    _p->eval(_state);
    float d, r, g, b;
    while (!_state.stk->empty()) {
      d = _state.stk->top(); _state.stk->pop();
      b = _state.stk->top(); _state.stk->pop();
      g = _state.stk->top(); _state.stk->pop();
      r = _state.stk->top(); _state.stk->pop();
      palette->addColor(d, r, g, b);
    }
  }
}


CyrilPalette::CyrilPalette (const CyrilPalette &other) {
  loc = other.loc;
  palette = other.palette->clone();
}
CyrilPalette::~CyrilPalette () {
  delete palette;
}

void CyrilPalette::print() {
  cout << "Palette" << endl;
}

Cyril* CyrilPalette::clone () {
  return new CyrilPalette (*this);
}

int CyrilPalette::size() {
  return 0;
}

void CyrilPalette::eval(CyrilState &_s) {
  (*_s.cs)[loc] = palette;
}


