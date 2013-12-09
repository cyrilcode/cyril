//
//  ShaderEvaluator.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__ShaderEvaluator__
#define __cyril__ShaderEvaluator__

#include "EditorEvaluator.h"

class ShaderEvaluator : public EditorEvaluator {
  int n;
  int type;
  string latest;
  ShaderEvaluator *partner;
public:
  ShaderEvaluator(int _t, int _i) : EditorEvaluator(), type(_t), n(_i) {}
  bool compileScript(string _s);
  void evaluate(EditorState *);
  void addOtherShader(ShaderEvaluator *);
  string getString();
};


#endif /* defined(__cyril__ShaderEvaluator__) */
