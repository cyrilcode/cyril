//
//  CyrilShapeList.cpp
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#include "CyrilShapeList.h"

CyrilShapeList::CyrilShapeList (Cyril* _c) : c(_c) {
  int sz = _c->size();
  if (!(sz == 2 || sz == 3)) {
    yyerror("Shape list point requires 2 or 3 arguments");
    valid = false;
  }
}

CyrilShapeList::CyrilShapeList (const CyrilShapeList &other) {
  c = other.c->clone ();
}
CyrilShapeList::~CyrilShapeList ()
{
  delete c;
}
void CyrilShapeList::print() {
  c->print();
  cout << "ShapeList point" << endl;
}
Cyril * CyrilShapeList::clone () {
  return new CyrilShapeList (*this);
}
int CyrilShapeList::size() {
  return 0;
}
void CyrilShapeList::eval(CyrilState &_s) {
  c->eval(_s);
  float x,y,z;
  switch (c->size()) {
    case 2:
      y = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      ofVertex(x,y);
      break;
    case 3:
      z = _s.stk->top(); _s.stk->pop();
      y = _s.stk->top(); _s.stk->pop();
      x = _s.stk->top(); _s.stk->pop();
      ofVertex(x,y,z);
      break;
  }
}

