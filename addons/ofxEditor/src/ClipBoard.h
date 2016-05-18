//
//  Clipboard.h
//  textEditor
//
//  Created by Darren Mothersele on 19/11/2013.
//
//

#ifndef __textEditor__Clipboard__
#define __textEditor__Clipboard__

#include "ofMain.h"

class ClipBoard {
  
public:
  static string getText();
  static bool setText(const string text);

};


#endif /* defined(__textEditor__Clipboard__) */
