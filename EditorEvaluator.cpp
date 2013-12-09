//
//  EditorEvaluator.cpp
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#include "EditorEvaluator.h"

/*
 * The compileScript and evaluate methods are to be 
 * overriden in a subclass with your required functionality.
 */

bool EditorEvaluator::compileScript(string _s) {
  valid = true;
  running = false;
  return true;
}

void EditorEvaluator::evaluate(EditorState *_state) {
  if (running && valid) {
    // evaluate
    // cout << "Evaluate" << endl;
  }
}

void EditorEvaluator::runCommand(string c) {
  // The default evaluator just echos commands back to cout
  cout << c << endl;
}

bool EditorEvaluator::pause() {
  running = false;
  return running;
}

bool EditorEvaluator::isRunning() {
  return running;
}
bool EditorEvaluator::isValid() {
  return valid;
}

void EditorEvaluator::setBuffer(EditorBuffer *_b) {
  buffer = _b;
}

