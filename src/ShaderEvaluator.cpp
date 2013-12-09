//
//  ShaderEvaluator.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "ShaderEvaluator.h"
#include "cyrilApp.h"

bool ShaderEvaluator::compileScript(string _s) {
  //cout << "Update shader " << n << endl;
  return ((cyrilApp*)ofGetAppPtr())->updateShader(type, n, _s, partner);
}

void ShaderEvaluator::evaluate(EditorState * _state) {

}
