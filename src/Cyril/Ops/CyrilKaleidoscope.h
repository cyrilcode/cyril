//
//  CyrilKaleidoscope.h
//  cyril
//
//  Created by Darren Mothersele on 12/09/2014.
//
//

#ifndef __cyril__CyrilKaleidoscope__
#define __cyril__CyrilKaleidoscope__

#include "Cyril.h"


class CyrilKaleidoscope : public Cyril {
protected:
  Cyril* e;
  int s;
public:
  CyrilKaleidoscope(Cyril* _e);
  CyrilKaleidoscope (const CyrilKaleidoscope &other);
  virtual ~CyrilKaleidoscope ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual void update(CyrilState &);
};


#endif /* defined(__cyril__CyrilKaleidoscope__) */
