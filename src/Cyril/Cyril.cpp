//
//  Cyril.cpp
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#include "Cyril.h"

Cyril* Cyril::clone () {
  return new Cyril (*this);
}

Cyril::Cyril (const Cyril &other) {
  valid = other.valid;
}

// How many items are left on the stack after eval?
int Cyril::size() {
  return 0;
}

void Cyril::eval(CyrilState &) {
  // Do nothing!
}