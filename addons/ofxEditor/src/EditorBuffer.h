//
//  EditorBuffer.h
//  textEditor
//
//  Created by Darren Mothersele on 19/11/2013.
//
//

#ifndef __textEditor__EditorBuffer__
#define __textEditor__EditorBuffer__

#include "ofMain.h"

class EditorBuffer {

  string text;
  string::iterator cursorPosition;
  string::iterator selectStart;
  string::iterator selectEnd;
  void updateSelect(bool);

  ofColor textColor;
  ofColor textBorderColor;
  ofColor cursorColor;
  ofColor highlightColor;

  float lineHeight;
  float charWidth;
  ofTrueTypeFont * font;

	vector<ofTTFCharacter> shapes;
  ofRectangle bounds;
  ofPoint cursorPoint;
  float minScale, maxScale;
  
public:
  EditorBuffer(ofTrueTypeFont * f);

  void insert(int);
  void insert(const string);
  void backspace();
  void clear();

  string getText();
  void setText(string);

  void moveCursorRow(int direction, bool shift, bool cmd);
  void moveCursorCol(int direction, bool shift, bool cmd);

  void setTextColor(ofColor, ofColor);
  void setCursorColor(ofColor);
  void setHighlightColor(ofColor);

  const string getSelection();
  void removeSelection();

  void setCursorPosition(int, int);
  int getCurrentRow();
  int getCurrentCol();

  void draw(float, float, float, float);
  ofRectangle getBoundingBox();
  void updateShapes();
  void updateBounds();
  void drawStrings();
  void drawCursor();
  
};

#endif /* defined(__textEditor__EditorBuffer__) */
