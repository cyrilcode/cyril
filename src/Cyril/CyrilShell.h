//
//  CyrilShell.h
//  cyril
//
//  Created by Darren Mothersele on 29/11/2013.
//
//

#ifndef __cyril__CyrilShell__
#define __cyril__CyrilShell__


#include "EditorEvaluator.h"
#include "CyrilState.h"

class CyrilShell : public EditorEvaluator {
  CyrilState *state;
  void printState();
  void clear();
  void shader(string _c);
  void newProg(string _c);
public:
  CyrilShell(CyrilState *_s) : state(_s) {}
  void runCommand(string c);
};


#endif /* defined(__cyril__CyrilShell__) */
