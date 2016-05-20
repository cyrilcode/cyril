//
// Created by Darren Mothersele on 20/05/2016.
//

#include "ofMain.h"
#include "cyrilApp.h"

map < string, ofColor > colorNameMap;

int main()
{
    string sourceCode = "rotate\nmove\nbox";

    Cyril* tempProg = CyrilParser::parseString(sourceCode);

    tempProg->print();

    exit(EXIT_SUCCESS);
}