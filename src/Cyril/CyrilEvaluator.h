//
//  CyrilEvaluator.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__CyrilEvaluator__
#define __cyril__CyrilEvaluator__

#include "EditorEvaluator.h"

class CyrilEvaluator : public EditorEvaluator {
  Cyril *prog;
public:
  bool compileScript(string _s);
  void evaluate(EditorState *);
};

#endif /* defined(__cyril__CyrilEvaluator__) */
