//
//  CyrilAnimStep.h
//  cyril2
//
//  Created by Darren Mothersele on 07/11/2013.
//
//

#ifndef __cyril2__CyrilAnimStep__
#define __cyril2__CyrilAnimStep__

#include "ofMain.h"
#include "Cyril.h"

class CyrilAnimStep : public Cyril {
  float n;
  Cyril* e1;
  Cyril* e2;
public:
  CyrilAnimStep(float _n, Cyril* _e1, Cyril* _e2);
  CyrilAnimStep (const CyrilAnimStep &other);
  virtual ~CyrilAnimStep ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilAnimStep__) */
