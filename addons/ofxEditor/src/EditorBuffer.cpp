//
//  EditorBuffer.cpp
//  textEditor
//
//  Created by Darren Mothersele on 19/11/2013.
//
//

#include "EditorBuffer.h"

EditorBuffer::EditorBuffer(ofTrueTypeFont * _f) :
text(),
cursorPosition(text.end()),
selectStart(text.end()),
selectEnd(text.end()),
font(_f),
minScale(0.5),
maxScale(2.5)
{
  lineHeight = font->getLineHeight();
  charWidth = font->stringWidth("X") + font->getLetterSpacing();
  cursorPosition = text.end();
  selectStart = cursorPosition;
  selectEnd = cursorPosition;
}

string EditorBuffer::getText() {
  return text;
}
void EditorBuffer::setText(string t) {
  text = t;
  cursorPosition = text.end();
  selectStart = cursorPosition;
  selectEnd = cursorPosition;
}

void EditorBuffer::insert(int key) {
  if (selectStart != selectEnd) {
    cursorPosition = text.erase(selectStart, selectEnd);
  }
  cursorPosition = text.insert(cursorPosition, key);
  cursorPosition++;
  updateSelect(false);
}

void EditorBuffer::insert(const string s) {
  int loc = cursorPosition - text.begin();
  text.insert(cursorPosition, s.begin(), s.end());
  cursorPosition = text.begin() + loc + s.size();
  updateSelect(false);
}

void EditorBuffer::updateSelect(bool shift) {
  if (shift) {
    if (cursorPosition > selectEnd) {
      selectEnd = cursorPosition;
    }
    else if (cursorPosition < selectStart) {
      selectStart = cursorPosition;
    }
  }
  else {
    selectStart = cursorPosition;
    selectEnd = cursorPosition;
  }
}

void EditorBuffer::backspace() {
  if (selectStart == selectEnd) {
    if (cursorPosition != text.begin()) {
      cursorPosition--;
      if (cursorPosition != text.end()) {
        cursorPosition = text.erase(cursorPosition);
      }
    }
  }
  else {
    cursorPosition = text.erase(selectStart, selectEnd);
  }
  updateSelect(false);
}


void EditorBuffer::setCursorPosition(int c, int r) {
  if (c >= 0 && r >= 0) {
    int currentRow = 0;
    cursorPosition = text.begin();
    while (currentRow < r) {
      if (*cursorPosition == '\n') currentRow++;
      cursorPosition++;
    }
    int currentCol = 0;
    while (currentCol < c && *cursorPosition != '\n') {
      cursorPosition++;
      currentCol++;
    }
  }
  else {
    cursorPosition = text.begin();
  }
  // Prevent cursor from moving outside of text
  if (cursorPosition < text.begin()) cursorPosition = text.begin();
  if (cursorPosition > text.end()) cursorPosition = text.end();
}


void EditorBuffer::clear() {
  text.clear();
  cursorPosition = text.end();
  selectStart = cursorPosition;
  selectEnd = cursorPosition;
}


void EditorBuffer::moveCursorRow(int direction, bool shift, bool cmd) {
  setCursorPosition(getCurrentCol(), getCurrentRow() + direction);
  updateSelect(shift);
}

void EditorBuffer::moveCursorCol(int direction, bool shift, bool cmd) {
  if (cmd) {
    // If command key is pressed move to next word
    bool notFound = true;
    while (notFound && cursorPosition > text.begin() && cursorPosition < text.end()) {
      char stop_chars[] = " {}[]()\n";
      cursorPosition += direction;
      updateSelect(shift);
      for (unsigned int i = 0; i < strlen(stop_chars); ++i) {
        if (*(cursorPosition + direction) == stop_chars[i]) {
          notFound = false;
          break;
        }
      }
    }
  }
  else {
    if (direction == -1 && cursorPosition != text.begin()) {
      cursorPosition--;
      updateSelect(shift);
    }
    if (direction == 1 && cursorPosition != text.end()) {
      cursorPosition++;
      updateSelect(shift);
    }
  }
}

const string EditorBuffer::getSelection() {
  return string(selectStart, selectEnd);
}

void EditorBuffer::removeSelection() {
  cursorPosition = text.erase(selectStart, selectEnd);
  updateSelect(false);
}


int EditorBuffer::getCurrentRow() {
  // To get current row count number of '\n' characters between
  // text.begin and cursorPosition
  int rowNo = 0;
  for (string::iterator i = text.begin(); i < cursorPosition; i++) {
    if (*i == '\n') rowNo++;
  }
  return rowNo;
}

int EditorBuffer::getCurrentCol() {
  // To get the current column count the number of characters between
  // cursorPosition and previous '\n' or text.begin()
  int colNo = 0;
  for (string::iterator i = cursorPosition - 1; i >= text.begin() && *i != '\n'; --i) {
    colNo++;
  }
  return colNo;
}


void EditorBuffer::setTextColor(ofColor _c1, ofColor _c2) {
  textColor = _c1;
  textBorderColor = _c2;
}
void EditorBuffer::setCursorColor(ofColor _c) {
  cursorColor = _c;
}
void EditorBuffer::setHighlightColor(ofColor _c) {
  highlightColor = _c;
}


void EditorBuffer::updateBounds() {
  bounds = ofRectangle(0, 0, 0, lineHeight);
  string ss;
  bool foundCursor = false;
  
  // keep track of selection areas
  shapes.clear();
  ofPath selection;
  ofPoint select;
  bool inHighlight = false;
  
  for (string::iterator i = text.begin(); i < text.end(); ++i) {
    if (i == cursorPosition) {
      cursorPoint = ofPoint(font->stringWidth(ss), bounds.height);
      foundCursor = true;
    }
    if (i == selectStart) {
      select = ofPoint(font->stringWidth(ss), bounds.height);
      select.y -= lineHeight;
      inHighlight = true;
    }
    if (i == selectEnd) {
      selection.rectangle(select.x, select.y, font->stringWidth(ss) - select.x, bounds.height - select.y);
      inHighlight = false;
    }
    if (*i == '\n') {
      if (inHighlight) {
        selection.rectangle(select.x, select.y, font->stringWidth(ss) - select.x, bounds.height - select.y);
      }
      bounds.growToInclude(font->stringWidth(ss), bounds.height);
      bounds.height += lineHeight;
      ss.clear();
      if (inHighlight) {
        select = ofPoint(font->stringWidth(ss), bounds.height);
        select.y -= lineHeight;
      }
    }
    else if (*i == ' ') {
      ss.push_back('_');
    }
    else {
      ss.push_back(*i);
    }
  }
  if (inHighlight) {
    selection.rectangle(select.x, select.y, font->stringWidth(ss) - select.x, bounds.height - lineHeight - select.y);
  }
  if (!foundCursor) {
    cursorPoint = ofPoint(font->stringWidth(ss), bounds.height);
  }
  bounds.growToInclude(font->stringWidth(ss), bounds.height);
  
  selection.setColor(highlightColor);
  shapes.push_back(selection);
}


void EditorBuffer::drawStrings() {
  float h = lineHeight;
  string ss;
  for (string::iterator i = text.begin(); i < text.end(); ++i) {
    if (*i == '\n') {
      font->drawString(ss, 0, h);
      h += lineHeight;
      ss.clear();
    }
    else {
      ss.push_back(*i);
    }
  }
  font->drawString(ss, 0, h);
}

void EditorBuffer::drawCursor() {
  
  ofPushMatrix();
  ofPushStyle();
  //ofTranslate(x, y);
  
  ofPopStyle();
  ofPopMatrix();
}

void EditorBuffer::draw(float x, float y, float w, float h) {
  ofPushMatrix();
  ofPushStyle();
  ofTranslate(x, y);
  
  // Need to calculate size of editor before drawing
  updateBounds();
  
  // Scale down if needed
  float scale = 1;
  if (bounds.width > 0 && bounds.height > 0) {
    scale = min(w / bounds.width, h / bounds.height);
    scale = min(scale, maxScale);
    scale = max(scale, minScale);
    ofScale(scale, scale);
  }
  
  // Move editor content if cursor is off screen
  float offsetY = (h / scale) - cursorPoint.y;
  if (offsetY < 0) {
    ofTranslate(0, offsetY);
  }
  float offsetX = (w / scale) - cursorPoint.x;
  if (offsetX < 0) {
    ofTranslate(offsetX, 0);
  }
  
  // Draw selected text highlight
  for (vector<ofTTFCharacter>::iterator i = shapes.begin(); i < shapes.end(); ++i) {
    (*i).draw();
  }

  // Draw text buffer content
  ofSetColor(textColor);
  drawStrings();
  

  // Draw cursor
  ofSetColor(cursorColor);
  ofRect(cursorPoint, 10, -lineHeight);

  ofPopStyle();
  ofPopMatrix();
}

void EditorBuffer::updateShapes() {
  shapes.clear();
  ofPoint location(0, lineHeight);
  bool foundCursor = false;
  bool inHighlight = false;
  ofPoint select;
  ofPath selection;
  selection.setColor(highlightColor);
  ofPath cursor;
  cursor.setColor(cursorColor);
  string ss;

  for (string::iterator i = text.begin(); i < text.end(); ++i) {
    if (i == cursorPosition) {
      cursorPoint = ofPoint(location.x, location.y);
      cursor.rectangle(location.x, location.y, 10, -lineHeight);
      foundCursor = true;
    }
    if (i == selectStart) {
      select = location;
      select.y -= lineHeight;
      inHighlight = true;
    }
    if (i == selectEnd) {
      selection.rectangle(select.x, select.y, location.x - select.x, location.y - select.y);
      inHighlight = false;
    }
    if (*i == '\n') {
      font->drawString(ss, 0, location.y);
      ss.clear();
      if (inHighlight) {
        selection.rectangle(select.x, select.y, location.x - select.x, location.y - select.y);
      }
      location.x = 0;
      location.y += lineHeight;
      if (inHighlight) {
        select = location;
        select.y -= lineHeight;
      }
    }
    else if (*i == ' ') {
      ss.push_back(' ');
      location.x += charWidth;
    }
    else {
      /*
      ofTTFCharacter c = font->getCharacterAsPoints(*i);
      c.setStrokeColor(textBorderColor);
      c.setStrokeWidth(1);
      ofSetColor(textColor);
      shapes.push_back(c);
      shapes.back().translate(location);
      */
      //font->drawString(*i, location.x, location.y);
      ss.push_back(*i);
      location.x += charWidth;
    }
  }
  if (inHighlight) {
    selection.rectangle(select.x, select.y, location.x - select.x, location.y - select.y);
  }
  if (!foundCursor) {
    cursorPoint = ofPoint(location.x, location.y);
    //cursor.rectangle(location.x, location.y, 10, -lineHeight);
    cursor.rectangle(font->stringWidth(ss), location.y, 10, -lineHeight);
  }
  font->drawString(ss, 0, location.y);
  shapes.push_back(cursor);
  shapes.push_back(selection);

  bounds = ofRectangle(0,0,0,0);
  for (vector<ofTTFCharacter>::iterator i = shapes.begin(); i < shapes.end(); ++i) {
    //(*i).draw();
    for (vector<ofPolyline>::iterator j = (*i).getOutline().begin(); j < (*i).getOutline().end(); ++j) {
      bounds.growToInclude((*j).getBoundingBox());
    }
  }
}



