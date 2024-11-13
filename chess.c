#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "gc.h"

void allocateMemory(char*** newFig, int rows, size_t cols){
  memoryAlloc((void**)newFig, sizeof(char*)*(rows + 1));
  for(int i = 0; i < rows; i++)
    memoryAlloc((void**)(*newFig + i), sizeof(char)*(cols + 1));
}

void unlinkMemory(char*** fig){
  countMemoryEntries();
  for(int i = 0; (*fig)[i]; i++)
    unregisterPointer((void**)(*fig + i));
  countMemoryEntries();
  unregisterPointer((void**)fig);
  countMemoryEntries();
}

char** reverse(char** fig){
  int rows = 0;
  while(fig[++rows]);
  
  int cols = 0;
  while(fig[0][++cols]);

  char** newFig;
  allocateMemory(&newFig, rows, cols);

  for(int i = 0; fig[i]; i++){
    for(int j = 0; fig[0][j]; j++)
      newFig[i][j] = fig[i][j];
    newFig[i][cols] = 0;
  }
  newFig[rows] = 0;
  unlinkMemory(&newFig);
  return newFig;
}

