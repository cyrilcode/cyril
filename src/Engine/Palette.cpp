//
//  Palette.cpp
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#include "Palette.h"

Palette::Palette() : total(0) {
  
}
void Palette::addColor(float _d, int _hex) {
  total += _d;
  colors.push_back(PaletteItem(_d, _hex));
}
void Palette::addColor(float _d, float _r, float _g, float _b) {
  total += _d;
  colors.push_back(PaletteItem(_d, _r, _g, _b));
}

void Palette::drawBackground() {
  // TODO: draw gradient background using palette variable
  //for (int y = 0; y < ofGetHeight(); y++) {
    //ofSetColor(lerp(y / ofGetHeight()));
    //ofLine(0, y, ofGetWidth(), y);
  //}
}

ofColor Palette::lerp(float _v) {
  PaletteItem first = colors.front();
  float newV = ofMap(ofClamp(_v, 0, 1), 0, 1, 0, total);
  float keepV = newV;

  bool findFirst = true;
  ofColor found, nextC;
  float prevD(0), nextD(0);
  for(vector<PaletteItem>::iterator it = colors.begin(); it != colors.end(); ++it){
    if (findFirst) {
      found = it->c;
      prevD += it->distance;
      newV -= it->distance;
      if (newV < 0) {
        findFirst = false;
        nextD = prevD;
      }
    }
    else {
      nextC = it->c;
      nextD += it->distance;
      break;
    }
  }
  if (prevD == nextD) {
    return colors.back().c;
  }
  return found.lerp(nextC, ofMap(keepV, prevD - first.distance, nextD, 0, 1));
}

ofColor Palette::getColor(float _v) {
  ofColor found;
  for(vector<PaletteItem>::iterator it = colors.begin(); it != colors.end(); ++it){
    found = it->c;
    _v -= it->distance;
    if (_v <= 0) break;
  }
  return found;
}
ofColor Palette::randomColor() {
  return getColor(ofRandom(total));
}
ofColor Palette::getColorAt(float _i) {
  return getColor(total * _i);
}

Palette::Palette (const Palette &other) {
  total = other.total;
  colors = * new vector<PaletteItem>(other.colors);
}
Palette::~Palette () {
  
}
Palette * Palette::clone () {
  return new Palette(* this);
}







