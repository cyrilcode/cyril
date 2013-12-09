#include "cyrilApp.h"


//--------------------------------------------------------------
void cyrilApp::setup(){
  
  // On first run we initialise or timers in the update() loop
  doResetTimers = true;
  
  // Configure sound stream for beat detection
  ofSoundStreamSetup(0, 1, this, 44100, beat.getBufferSize(), 4);
  
  // Default to black background
  ofBackground(0);
  
  allocateDrawBuffer(ofGetWidth(), ofGetHeight());
  
  // Add our extra commands to the editor
  editor.addCommand('f', this, &cyrilApp::toggleFullscreen);
  editor.addCommand('d', this, &cyrilApp::toggleBackground);
  editor.addCommand('k', this, &cyrilApp::toggleLights);
  editor.addCommand('l', this, &cyrilApp::loadFile);
  editor.addCommand('s', this, &cyrilApp::saveFile);
  editor.addCommand('e', this, &cyrilApp::resetTimers);
  
  // Add REPL/shell/console buffer
  editor.addShell(new CyrilShell(&_state));
  editor.currentBuffer = 0;
  editorVisible = true;
  
  
  // Initialise state
  _state.init();
  _state.setDefaults();
  
  // Reserve some space for Particle System
  _state.ps->reserve(2000);
  
  toggleFullscreen(this);
  toggleLights(this);
  
}

bool cyrilApp::updateShader(int _t, int _n, string _s, ShaderEvaluator *_other) {
  (*_state.shaders)[_n]->setupShaderFromSource(_t, _s);
  return (*_state.shaders)[_n]->linkProgram();
}

//--------------------------------------------------------------
void cyrilApp::update(){
  
  // Update state
  _state.update(doResetTimers, beat);
  doResetTimers = false;
  
  // Update particles
  for(vector<Particle*>::iterator it = _state.ps->begin(); it != _state.ps->end(); ++it){
    (*it)->update();
  }
  // Remove dead particles
  ofRemove(*_state.ps, Particle::isDead);
  
  editor.update();
}

//--------------------------------------------------------------
void cyrilApp::draw(){
  
  ofEnableDepthTest();
  
  if (!autoClearBg) {
    drawing.begin();
  }
  
  if (lightsOn) _state.lightsOn();
  else ofDisableLighting();

  // Evaluate all Cyril scripts from editor buffers
  editor.evaluateAll(&_state);
  
  // Evaluate all particles
  for(vector<Particle*>::iterator it = _state.ps->begin(); it != _state.ps->end(); ++it){
    (*it)->draw(&_state);
  }
  
  if (lightsOn) _state.lightsOff();
  
  if (!autoClearBg) {
    drawing.end();
    ofDisableLighting();
    ofSetColor(255,255,255,255);
    drawing.draw(0, 0);
  }
  
  if (editorVisible) {
    ofDisableDepthTest();
  	editor.draw();
  }
}



void cyrilApp::toggleFullscreen(void * _o) {
  ((cyrilApp *)_o)->isFullScreen = !((cyrilApp *)_o)->isFullScreen;
  ofSetFullscreen(((cyrilApp *)_o)->isFullScreen);
  
  if (((cyrilApp *)_o)->isFullScreen) {
    ofHideCursor();
#ifdef __APPLE__
    CGDisplayHideCursor(NULL); 
#endif
  }
  else {
    ofShowCursor();
#ifdef __APPLE__
    CGDisplayShowCursor(NULL);
#endif
  }
}
void cyrilApp::toggleEditor(void * _o) {
  ((cyrilApp *)_o)->editorVisible = !((cyrilApp *)_o)->editorVisible;
}
void cyrilApp::toggleBackground(void * _o) {
  ((cyrilApp *)_o)->autoClearBg = !((cyrilApp *)_o)->autoClearBg;
}
void cyrilApp::toggleLights(void * _o) {
  ((cyrilApp *)_o)->lightsOn = !((cyrilApp *)_o)->lightsOn;
  ofEnableLighting();
  ofSetSmoothLighting(true);
  ((cyrilApp *)_o)->_state.light->setAmbientColor(ofColor(0,0,0));
  ((cyrilApp *)_o)->_state.light->setDiffuseColor(ofColor(255,255,255));
  ((cyrilApp *)_o)->_state.light->setSpecularColor(ofColor(255,255,255));
  ((cyrilApp *)_o)->_state.light->setPointLight();
  ((cyrilApp *)_o)->_state.light->setAttenuation(1.f,0.f,0.f);
}

void cyrilApp::loadFile(void * _o) {
  int whichEditor = ((cyrilApp *)_o)->editor.currentBuffer;
	((cyrilApp *)_o)->editor.loadFile(ofToString(whichEditor)+".txt", whichEditor);
  ((cyrilApp *)_o)->editor.update();
}
void cyrilApp::saveFile(void * _o) {
  int whichEditor = ((cyrilApp *)_o)->editor.currentBuffer;
	((cyrilApp *)_o)->editor.saveFile(ofToString(whichEditor)+".txt", whichEditor);
}
void cyrilApp::resetTimers(void * _o) {
  ((cyrilApp *)_o)->doResetTimers = true;
}


//--------------------------------------------------------------
void cyrilApp::keyPressed(int key){

}

//--------------------------------------------------------------
void cyrilApp::keyReleased(int key){

}

//--------------------------------------------------------------
void cyrilApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void cyrilApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void cyrilApp::mousePressed(int x, int y, int button){
  mouseOn = true;
}

//--------------------------------------------------------------
void cyrilApp::mouseReleased(int x, int y, int button){
  mouseOn = false;
}


//--------------------------------------------------------------
void cyrilApp::windowResized(int w, int h){
  _state.resize(w, h);
  allocateDrawBuffer(w, h);
}

void cyrilApp::allocateDrawBuffer(int w, int h) {
  // Configure ofFbo for drawing to
  ofFbo::Settings settings;
  settings.width = w;
  settings.height = h;
  settings.useDepth = true;
  settings.numSamples = 1;
  settings.internalformat = GL_RGBA;
  drawing.allocate(settings);
  drawing.begin();
  ofClear(0,0,0,0);
  drawing.end();
}

//--------------------------------------------------------------
void cyrilApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void cyrilApp::dragEvent(ofDragInfo dragInfo){

}


void cyrilApp::audioReceived(float* input, int bufferSize, int nChannels) {
  beat.audioReceived(input, bufferSize, nChannels);
}


