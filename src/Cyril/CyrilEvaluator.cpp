//
//  CyrilEvaluator.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "CyrilParser.h"
#include "CyrilEvaluator.h"

bool CyrilEvaluator::compileScript(string _s) {
  // cout << "Compile Cyril script" << endl;
  prog = CyrilParser::parseString(_s);
  if (prog->valid) {
    valid = true;
    running = true;
  }
  else {
    valid = false;
    running = false;
  }
  return valid;
}

void CyrilEvaluator::evaluate(EditorState * _state) {
  if (running && valid) {
    // cout << "Evaluate Cyril" << endl;
    prog->eval(*(CyrilState*)_state);
  }
}

