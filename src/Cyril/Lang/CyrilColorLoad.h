//
//  CyrilColorLoad.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilColorLoad__
#define __cyril2__CyrilColorLoad__

#include "ofMain.h"
#include "cmds.h"
#include "Cyril.h"

class CyrilColorLoad : public Cyril {
  int loc;
public:
  CyrilColorLoad(int _i);
  CyrilColorLoad (const CyrilColorLoad &other) ;
  virtual ~CyrilColorLoad ();
  void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilColorLoad__) */
