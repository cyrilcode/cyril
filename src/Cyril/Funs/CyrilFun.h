//
//  CyrilFun.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilFun_h
#define cyril2_CyrilFun_h

#include "ofMain.h"
#include "Cyril.h"
#include "cmds.h"

class CyrilFun : public Cyril {
protected:
  Cyril* c;
public:
  CyrilFun(Cyril* _c = NULL);
  CyrilFun(const CyrilFun &other);
  virtual ~CyrilFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif
