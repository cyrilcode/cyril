//
//  CyrilTileOp.cpp
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#include "CyrilTile.h"

CyrilTile::CyrilTile (Cyril* _e, Cyril* _c) : e(_e), c(_c) {
  int s = e->size();
  if (!(s == 1 || s == 2 || s == 3)) {
    yyerror("Tile command takes 1, 2, 3 or 4 arguments");
    valid = false;
  }
}

CyrilTile::CyrilTile (const CyrilTile &other) {
  e = other.e->clone ();
  c = other.c->clone ();
}
CyrilTile::~CyrilTile ()
{
  delete c;
}
void CyrilTile::print() {
  c->print();
  cout << "Tile" << endl;
}
Cyril * CyrilTile::clone () {
  return new CyrilTile (*this);
}
int CyrilTile::size() {
  return 0;
}
void CyrilTile::eval(CyrilState &_s) {
  float w,h,d;
  float step = 1;
  e->eval(_s);
  switch (e->size()) {
    case 1:
      d = 1;
      h = 1;
      w = _s.stk->top(); _s.stk->pop();
      break;
    case 2:
      d = 1;
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      break;
    case 3:
      d = _s.stk->top(); _s.stk->pop();
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      break;
    case 4:
      step = _s.stk->top(); _s.stk->pop();
      d = _s.stk->top(); _s.stk->pop();
      h = _s.stk->top(); _s.stk->pop();
      w = _s.stk->top(); _s.stk->pop();
      break;
  }
  float xMin = (step - (w * step)) / 2.0;
  float xMax = ((w * step) - step) / 2.0;
  float yMin = (step - (h * step)) / 2.0;
  float yMax = ((h * step) - step) / 2.0;
  float zMin = (step - (d * step)) / 2.0;
  float zMax = ((d * step) - step) / 2.0;
  for (float x = xMin; x <= xMax; x += step) {
    for (float y = yMin; y <= yMax; y += step) {
      for (float z = zMin; z <= zMax; z += step) {
        ofPushMatrix();
        ofTranslate(x, y, z);
        c->eval(_s);
        ofPopMatrix();
      }
    }
  }
}

