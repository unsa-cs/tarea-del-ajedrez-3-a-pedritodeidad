#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "gc.h"

char** allocateMemory(int rows, size_t cols){
  char** newFig;
  memoryAlloc((void**)&newFig, sizeof(char*)*(rows + 1));
  fprintf(stderr, "Todo correcto :)\n");
  countMemoryEntries();
  for(int i = 0; i < rows; i++){
    memoryAlloc((void**)&newFig[i], sizeof(char)*(cols + 1));
    fprintf(stderr, "Prueba: %d\n", i);//
    countMemoryEntries();
  }
  return newFig;
}

void unlinkMemory(char** fig){
  countMemoryEntries();
  for(int i = 0; fig[i]; i++){
    unregisterPointer((void**)&fig[i]);
    //Para comprobar si dicho puntero se libero
    fprintf(stderr, "Liberado: %d\n", i);
    countMemoryEntries();
    if(i == 57){
      // Por si acaso hay un problema en unregisterPointer
      // El problema esta en la fila 58, fig[58]
      unregisterPointer((void**)&fig[i + 1]);
      fprintf(stderr, "Liberado: %d\n", i + 1);
      countMemoryEntries();
    }
    ////////////////////////////////////////////
  }
  countMemoryEntries();
  //Algo raro pasa aqui :v
  unregisterPointer((void**)&fig);
  countMemoryEntries();
}

char** reverse(char** fig){
  int rows = 0;
  while(fig[++rows]);
  
  int cols = 0;
  while(fig[0][++cols]);

  char** newFig = allocateMemory(rows, cols);

  for(int i = 0; fig[i]; i++){
    for(int j = 0; fig[0][j]; j++)
      newFig[i][j] = fig[i][j];
    newFig[i][cols] = 0;
  }
  newFig[rows] = 0;
  unlinkMemory(newFig);
  return newFig;
}

