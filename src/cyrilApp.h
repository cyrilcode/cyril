#pragma once
// #define CYRIL_DEBUG

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Particle.h"
#include "CyrilParser.h"
#include "CyrilEvaluator.h"
#include "ShaderEvaluator.h"
#include "CyrilShell.h"

#include "ofxEditor.h"
#include "ofxBeat.h"

class cyrilApp : public ofBaseApp{
  
  ofxBeat beat;
  
  ofFbo drawing;
  
  //ofxXmlSettings settings;
  string fileName;
  
  Cyril *prog[9];
  bool running[9];
  bool error[9];
  
  CyrilState _state;
  vector<string> progFiles;
  int currentProg;
  bool reportError;
  
  bool lightsOn;
  
  bool autoClearBg;
  bool pauseProg;
  bool runningProg;
  bool overlay;
  bool editorVisible;
  bool cursorVisible;
  bool isFullScreen;
  bool doResetTimers;
  
  void allocateDrawBuffer(int w, int h);
  
public:
  
	ofxEditor editor;
  
  cyrilApp(): editor("DroidSansMono.ttf"), isFullScreen(false), autoClearBg(true), mouseOn(false), lightsOn(false) {}
  
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void applyGlobalSettings();
  void reloadSettings();
  void runProgram();
  
  void audioReceived(float*, int, int);
  
  // Editor command callbacks 
  static void toggleFullscreen(void *);
  static void toggleEditor(void *);
  static void toggleBackground(void *);
  static void toggleLights(void *);
  static void loadFile(void *);
  static void saveFile(void *);
  static void resetTimers(void *);
  // Editor buffer callbacks
  static void pauseProgram(void *);
  static bool runScript(void *);
  
  // Variable to store he current mouse click status
  bool mouseOn;
  
  bool updateShader(int _t, int _n, string _s, ShaderEvaluator *_other);
  
};

