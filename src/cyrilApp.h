#pragma once
// #define CYRIL_DEBUG

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Particle.h"
#include "CyrilParser.h"

#include "ofxEditor.h"
#include "ofxBeat.h"

#include "ofxSyphon.h"

#include "ofxPostProcessing.h"
#define FX_KALEIDOSCOPE 0
#define FX_NOISE_WARP 1
#define FX_PIXELATE 2
#define FX_BLOOM 3

#include "ofxOsc.h"
// listen on port 12345
#define PORT 12345

#include "ofxIO.h"
using namespace ofx::IO;


class cyrilApp : public ofBaseApp{
  
	ofxEditor editor;
  ofxBeat beat;
  
	//ofxSyphonServer mainOutputSyphonServer;
	//ofxSyphonClient mClient;
  //ofxOscReceiver receiver;
  
  //ofxXmlSettings settings;
  string fileName;
  
  Cyril *prog[10];
  bool running[10];
  bool error[10];
  
  CyrilState _state;
  vector<string> progFiles;
  int currentProg;
  bool reportError;

  ofFbo edBuf;

  bool lightsOn;
  bool fxOn;
  
  bool autoClearBg;
  bool pauseProg;
  bool runningProg;
  bool overlay;
  bool editorVisible;
  bool cursorVisible;
  bool isFullScreen;
  bool doResetTimers;
  bool isOrtho;
  
  int lastSignalReport;
  
  DirectoryWatcherManager codeWatcher;
  DirectoryWatcherManager spriteWatcher;
  HiddenFileFilter fileFilter;
  
  void initPPFx();
  
public:
  
  cyrilApp(): editor(10, "../Resources/DroidSansMono.ttf") {}
  
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
  
  void reloadFileBuffer(std::string);
  
  // Editor command callbacks
  static void toggleFx(void *);
  static void toggleFullscreen(void *);
  static void toggleOrtho(void *);
  static void toggleEditor(void *);
  static void toggleBackground(void *);
  static void toggleLights(void *);
  static void loadFile(void *);
  static void saveFile(void *);
  static void resetTimers(void *);
  static void pauseProgram(void *);
  static void runScript(void *);
  
  // Directory watcher callbacks
  void onDirectoryWatcherItemAdded(const DirectoryWatcherManager::DirectoryEvent& evt);
  void onDirectoryWatcherItemRemoved(const DirectoryWatcherManager::DirectoryEvent& evt);
  void onDirectoryWatcherItemModified(const DirectoryWatcherManager::DirectoryEvent& evt);
  void onDirectoryWatcherItemMovedFrom(const DirectoryWatcherManager::DirectoryEvent& evt);
  void onDirectoryWatcherItemMovedTo(const DirectoryWatcherManager::DirectoryEvent& evt);
  void onDirectoryWatcherError(const Poco::Exception& exc);

};

