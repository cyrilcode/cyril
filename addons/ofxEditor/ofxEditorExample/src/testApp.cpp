#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  
  editor.addCommand('f', this, &testApp::toggleFullscreen);
  editor.addCommand('a', this, &testApp::toggleEditor);
  
  ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
  
  if (editorVisible) {
    editor.draw();
  }
}


void testApp::toggleEditor(void * _o) {
  ((testApp *)_o)->editorVisible = !((testApp *)_o)->editorVisible;
}


void testApp::toggleFullscreen(void *_o) {
  ((testApp *)_o)->isFullscreen = !((testApp *)_o)->isFullscreen;
  ofSetFullscreen(((testApp *)_o)->isFullscreen);
  if (((testApp *)_o)->isFullscreen) {
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



//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
