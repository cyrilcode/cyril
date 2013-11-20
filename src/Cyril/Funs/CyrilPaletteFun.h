//
//  CyrilPaletteFun.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilPaletteFun__
#define __cyril2__CyrilPaletteFun__

#include "ofMain.h"
#include "CyrilFun.h"
#include "Palette.h"

class CyrilPaletteFun : public CyrilFun {
public:
  CyrilPaletteFun(Cyril* _c);
  CyrilPaletteFun(const CyrilPaletteFun &other);
  virtual ~CyrilPaletteFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};

#endif /* defined(__cyril2__CyrilPaletteFun__) */
