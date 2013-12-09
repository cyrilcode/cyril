//
//  EditorEvaluator.h
//  cyril
//
//  Created by Darren Mothersele on 28/11/2013.
//
//

#ifndef __cyril__EditorEvaluator__
#define __cyril__EditorEvaluator__

#include "ofMain.h"

class EditorBuffer;

class EditorState {
  
};

class EditorEvaluator {
protected:
  bool running;
  bool valid;
  EditorBuffer *buffer;
public:
  EditorEvaluator() : running(false), valid(true) {}
  
  // Compile a string and return TRUE and set running to
  // TRUE if valid, otherwise return FALSE
  virtual bool compileScript(string _s);
  
  // Evaluate the last compiled script using the provided state
  virtual void evaluate(EditorState *_state);
  
  // Toggle the paused/running state of the evaluator
  // and return TRUE if now running, FALSE if now paused
  bool pause();
  
  virtual void runCommand(string c);
  
  bool isRunning();
  bool isValid();
  
  void setBuffer(EditorBuffer *_b);
};

#endif /* defined(__cyril__EditorEvaluator__) */
