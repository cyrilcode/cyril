#pragma once
// #define CYRIL_DEBUG

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Particle.h"
#include "CyrilParser.h"

#include "ofxEditor.h"
#include "ofxBeat.h"

class cyrilApp : public ofBaseApp{
  
	ofxEditor editor;
  ofxBeat beat;
  
  //ofxXmlSettings settings;
  string fileName;
  
  Cyril *prog[9];
  bool running[9];
  bool error[9];
  
  CyrilState _state;
  vector<string> progFiles;
  int currentProg;
  bool reportError;

  ofFbo edBuf;

  bool lightsOn;
  
  bool autoClearBg;
  bool pauseProg;
  bool runningProg;
  bool overlay;
  bool editorVisible;
  bool cursorVisible;
  bool isFullScreen;
  bool doResetTimers;
  
  int lastSignalReport;
  
public:
  
  cyrilApp(): editor(9, "DroidSansMono.ttf") {}
  
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
  static void pauseProgram(void *);
  static void runScript(void *);
  
};

