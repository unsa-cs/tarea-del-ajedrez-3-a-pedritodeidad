#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  //char** figure;
  //figure = (char**)malloc(sizeof(char**));
  //*figure = (char*)malloc(sizeof(char*));
  //figure[0][0] = 0; 
  //char** prueba = reverse(figure);
  interpreter(blackSquare);
  garbageCollector();
}
