//
//  CyrilShape.h
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#ifndef __Cyril__CyrilShape__
#define __Cyril__CyrilShape__

#include "ofMain.h"
#include "Cyril.h"

class CyrilShape : public Cyril {
  Cyril* e;
public:
  CyrilShape(Cyril* _e);
  CyrilShape (const CyrilShape &other);
  virtual ~CyrilShape ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};




#endif /* defined(__Cyril__CyrilShape__) */
