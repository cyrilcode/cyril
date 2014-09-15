//
//  CyrilBloom.h
//  cyril
//
//  Created by Darren Mothersele on 15/09/2014.
//
//

#ifndef __cyril__CyrilBloom__
#define __cyril__CyrilBloom__

#include "Cyril.h"

class CyrilBloom : public Cyril {
protected:
  Cyril* e;
  int s;
  float prevBloom;
public:
  CyrilBloom(Cyril* _e);
  CyrilBloom (const CyrilBloom &other);
  virtual ~CyrilBloom ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual void update(CyrilState &);
};


#endif /* defined(__cyril__CyrilBloom__) */
