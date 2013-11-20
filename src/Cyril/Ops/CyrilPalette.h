//
//  CyrilPalette.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilPalette__
#define __cyril2__CyrilPalette__

#include "ofMain.h"
#include "cmds.h"
#include "Cyril.h"
#include "Palette.h"

class CyrilPalette : public Cyril {
  int loc;
  Palette* palette;
public:
  CyrilPalette(int _l, Cyril* _p);
  CyrilPalette (const CyrilPalette &other) ;
  virtual ~CyrilPalette ();
  void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};
#endif /* defined(__cyril2__CyrilPalette__) */
