//
//  CyrilDie.h
//  cyril
//
//  Created by Darren Mothersele on 13/04/2015.
//
//

#ifndef cyril_CyrilDie_h
#define cyril_CyrilDie_h

#include "ofMain.h"
#include "CyrilOp.h"

class CyrilDie : public CyrilOp {
public:
    CyrilDie(Cyril* _c);
    CyrilDie (const CyrilDie &other);
    virtual ~CyrilDie ();
    virtual void print();
    virtual Cyril *clone ();
    virtual int size();
    virtual void eval(CyrilState &);
};


CyrilDie::CyrilDie (Cyril* _c) : CyrilOp(_c) {
    int s = c->size();
    if (!(s == 0)) {
        yyerror("Die command requires no arguments");
        valid = false;
    }
}

CyrilDie::CyrilDie (const CyrilDie &other) {
    c = other.c->clone ();
}
CyrilDie::~CyrilDie ()
{
    delete c;
}
void CyrilDie::print() {
    c->print();
    cout << "Die" << endl;
}
Cyril * CyrilDie::clone () {
    return new CyrilDie (*this);
}
int CyrilDie::size() {
    return 0;
}
void CyrilDie::eval(CyrilState &_s) {
    //c->eval(_s);
    valid = false;
}

#endif
