//
//  CyrilShapeList.h
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#ifndef __Cyril__CyrilShapeList__
#define __Cyril__CyrilShapeList__

#include "ofMain.h"
#include "Cyril.h"

class CyrilShapeList : public Cyril {
  Cyril* e;
  Cyril* c;
public:
  CyrilShapeList(Cyril* _c);
  CyrilShapeList (const CyrilShapeList &other);
  virtual ~CyrilShapeList ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__Cyril__CyrilShapeList__) */
