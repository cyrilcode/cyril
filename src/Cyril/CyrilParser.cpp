//
//  CyrilParser.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "CyrilParser.h"
#include "y.tab.h"
extern void scannerRestart();

Cyril* CyrilParser::parseString(string progStr) {
  //const char *str = progStr.c_str();
  int res = 0;
  progStr.append(1, '\n');
  res = yycyrilParseString(progStr.c_str());
  if (res == 0) {
#ifdef DEBUG_PRINT
    cout << "Compile OK" << endl;
#endif
    if (pRoot->matchPushPop() != 0) {
      //ofLog(OF_LOG_NOTICE, "Unmatched push and pop matrix");
      cout << "[error] Unmatched push and pop matrix" << endl;
      pRoot->valid = false;
    }
  }
  else {
    cout << "[error] Compile error" << endl;
    pRoot = new Cyril();
    pRoot->valid = false;
  }
  return pRoot;
  return new Cyril();
}

Cyril* CyrilParser::parseFile(string fileName) {
  ofFile file;
  // open file, read only, not binary
  file.open(ofToDataPath(fileName), ofFile::ReadOnly, false);
  ofBuffer buf = file.readToBuffer();
  return CyrilParser::parseString(buf.getText());
  /*
  //Cyril * pAST;
  int res = 0;
  FILE *fp=fopen(ofToDataPath(fileName).c_str(),"r");
  if(!fp) {
#ifdef DEBUG_PRINT
    cout << "Error opening file" << fileName << endl;
#endif
  }
  else {
#ifdef DEBUG_PRINT
    cout << "parsing file " << fileName << endl;
#endif
    scannerRestart();
    line_no = 0;
    yyin = fp;
    res = yyparse();
    fclose(fp);
    if (res == 0) {
#ifdef DEBUG_PRINT
      cout << "Compile OK" << endl;
#endif
    }
  }
  return pRoot;
  */
}