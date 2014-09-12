//
//  CyrilNoiseWarp.h
//  cyril
//
//  Created by Darren Mothersele on 12/09/2014.
//
//

#ifndef __cyril__CyrilNoiseWarp__
#define __cyril__CyrilNoiseWarp__

#include "Cyril.h"


class CyrilNoiseWarp : public Cyril {
protected:
  Cyril* e;
public:
  CyrilNoiseWarp(Cyril* _e);
  CyrilNoiseWarp (const CyrilNoiseWarp &other);
  virtual ~CyrilNoiseWarp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual void update(CyrilState &);
};


#endif /* defined(__cyril__CyrilNoiseWarp__) */
