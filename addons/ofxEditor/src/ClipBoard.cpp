/*
* Copyright (C) 2012 Akira Hayasaka & Dan Wilcox <danomatika@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*
* See https://github.com/Akira-Hayasaka/ofxGLEditor for more info.
*/

#include "Clipboard.h"

string ClipBoard::getText() {
  
#ifdef TARGET_OSX
  OSStatus             err = noErr;
  ItemCount            itemCount;
  PasteboardSyncFlags  syncFlags;
  static PasteboardRef inPasteboard = NULL;
  PasteboardCreate( kPasteboardClipboard, &inPasteboard );
  char* data;
  data = NULL;
  
  syncFlags = PasteboardSynchronize( inPasteboard );
  err = badPasteboardSyncErr;
  
  err = PasteboardGetItemCount( inPasteboard, &itemCount );
  require_noerr( err, CantGetPasteboardItemCount );
  
  for( int itemIndex = 1; itemIndex <= itemCount; itemIndex++ ) {
    PasteboardItemID  itemID;
    CFDataRef  flavorData;
    
    err = PasteboardGetItemIdentifier( inPasteboard, itemIndex, &itemID );
    require_noerr( err, CantGetPasteboardItemIdentifier );
    
    err = PasteboardCopyItemFlavorData( inPasteboard,
                                       itemID, CFSTR("public.utf8-plain-text"), &flavorData );
    data = (char*)CFDataGetBytePtr(flavorData);
    
  CantGetPasteboardItemIdentifier:
    ;
  }
  
CantGetPasteboardItemCount:
  return (string) data;
  
#else
  
  ofLog(OF_LOG_WARNING, "ofxGLEditor: sorry, copying to the system clipboard is not supported on your OS yet");
  return "";
  
#endif
}

bool ClipBoard::setText(const string text) {
  
#ifdef TARGET_OSX
  
  OSStatus                err = noErr;
  static PasteboardRef    pasteboard = NULL;
  PasteboardCreate( kPasteboardClipboard, &pasteboard );
  
  err = PasteboardClear( pasteboard );
  require_noerr( err, PasteboardClear_FAILED );
  
  CFDataRef  data;
  
  data = CFDataCreate(kCFAllocatorDefault, (UInt8*) text.c_str(), strlen(text.c_str())+1);
  err = PasteboardPutItemFlavor( pasteboard, (PasteboardItemID)1, kUTTypeUTF8PlainText, data, 0);
  require_noerr( err, PasteboardPutItemFlavor_FAILED );
  
  return true;
  
PasteboardPutItemFlavor_FAILED:
  ofLog(OF_LOG_ERROR, "ofxGLEditor: pasting from the pasteboard failed");
  return false;
  
PasteboardClear_FAILED:
  ofLog(OF_LOG_ERROR, "ofxGLEditor: clearing the cliboard failed");
  return false;
  
#else
  
  ofLog(OF_LOG_WARNING, "ofxGLEditor: sorry, pasting from the system clipboard is not supported on your OS yet");
  return true;
  
#endif
}

