//
//  Palette.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__Palette__
#define __cyril2__Palette__

#include "ofMain.h"

class PaletteItem {
public:
  ofColor c;
  float distance;
  
  PaletteItem(float _d, int _hex) {
    c = ofColor::fromHex(_hex);
    distance = _d;
  }
  PaletteItem(float _d, float _r, float _g, float _b) {
    c = ofColor(_r, _g, _b);
    distance = _d;
  }
};

class Palette {
  float total;
  vector<PaletteItem> colors;
public:
  Palette();
  void addColor(float, int);
  void addColor(float, float, float, float);
  ofColor getColor(float);
  ofColor randomColor();
  ofColor getColorAt(float);
  ofColor lerp(float);
  Palette (const Palette &other) ;
  virtual ~Palette ();
  virtual Palette *clone ();
  void drawBackground();
};


#endif /* defined(__cyril2__Palette__) */
