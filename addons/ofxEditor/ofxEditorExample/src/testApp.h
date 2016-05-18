#pragma once

#include "ofMain.h"
#include "ofxEditor.h"


class testApp : public ofBaseApp{
  
  ofxEditor editor;
  bool editorVisible;
  bool isFullscreen;
  
	public:
  testApp() : editor(9), editorVisible(true), isFullscreen(false) {}
  
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
  
  // Editor command callbacks are static methods
  static void toggleFullscreen(void *);
  static void toggleEditor(void *);
};
