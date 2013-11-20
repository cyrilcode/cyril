//
//  CyrilParser.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilParser_h
#define cyril2_CyrilParser_h

#include "ofMain.h"
#include "Cyril.h"
#include "CyrilList.h"
#include "CyrilOp.h"
#include "CyrilAssign.h"
#include "CyrilPush.h"
#include "CyrilDo.h"
#include "CyrilFor.h"
#include "CyrilIf.h"
#include "CyrilWhile.h"
#include "CyrilHexColor.h"
#include "CyrilFun.h"
#include "CyrilBinaryOp.h"
#include "CyrilLoad.h"
#include "CyrilUnaryOp.h"
#include "CyrilParticle.h"

extern "C" int yyparse();
extern FILE *yyin;
extern "C" int line_no;
extern Cyril * pRoot;
extern int yycyrilParseString(const char *str);

class CyrilParser {
public:
  static Cyril* parseString(string progStr);
  static Cyril* parseFile(string fileName);
};

#endif

