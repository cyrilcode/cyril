//
//  CyrilAnimation.h
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#ifndef __cyril2__CyrilAnimation__
#define __cyril2__CyrilAnimation__

#include "ofMain.h"
#include "Cyril.h"

class CyrilAnimation : public Cyril {
  Cyril* e;
public:
  CyrilAnimation(Cyril* _e);
  CyrilAnimation (const CyrilAnimation &other);
  virtual ~CyrilAnimation ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilAnimation__) */
