//
//  CyrilPixelate.h
//  cyril
//
//  Created by Darren Mothersele on 15/09/2014.
//
//

#ifndef __cyril__CyrilPixelate__
#define __cyril__CyrilPixelate__

#include "Cyril.h"


class CyrilPixelate : public Cyril {
protected:
  Cyril* e;
  int s;
public:
  CyrilPixelate(Cyril* _e);
  CyrilPixelate (const CyrilPixelate &other);
  virtual ~CyrilPixelate ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual void update(CyrilState &);
};

#endif /* defined(__cyril__CyrilPixelate__) */
