//
//  CyrilTileOp.h
//  Cyril
//
//  Created by Darren Mothersele on 17/11/2013.
//
//

#ifndef __Cyril__CyrilTileOp__
#define __Cyril__CyrilTileOp__

#include "Cyril.h"


class CyrilTile : public Cyril {
protected:
  Cyril* e;
  Cyril* c;
public:
  CyrilTile(Cyril* _e, Cyril* _c);
  CyrilTile (const CyrilTile &other);
  virtual ~CyrilTile ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
  virtual void eval(CyrilState &);
  virtual int matchPushPop() { return c->matchPushPop(); }
};

#endif /* defined(__Cyril__CyrilTileOp__) */
