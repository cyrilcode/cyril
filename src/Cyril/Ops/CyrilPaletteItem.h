//
//  CyrilPaletteItem.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__CyrilPaletteItem__
#define __cyril2__CyrilPaletteItem__

#include "ofMain.h"
#include "cmds.h"
#include "Cyril.h"
#include "Palette.h"

class CyrilPaletteItem : public Cyril {
  Cyril* e;
  bool paletteCalc;
  float d,r,g,b;
public:
  CyrilPaletteItem(float _f, Cyril* _e);
  CyrilPaletteItem (const CyrilPaletteItem &other) ;
  virtual ~CyrilPaletteItem ();
  void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
};


#endif /* defined(__cyril2__CyrilPaletteItem__) */
