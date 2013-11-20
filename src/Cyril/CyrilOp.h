//
//  CyrilOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilOp_h
#define cyril2_CyrilOp_h

#include "ofMain.h"
#include "cmds.h"
#include "Cyril.h"

class CyrilOp : public Cyril {
protected:
  Cyril* c;
public:
  
  CyrilOp(Cyril* _c = NULL);
  CyrilOp(const CyrilOp &other);
  virtual ~CyrilOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif
