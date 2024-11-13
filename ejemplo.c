#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  //char** joinbw = join(blackSquare, whiteSquare);
  interpreter(blackSquare);
  garbageCollector();
}
