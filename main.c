#include <stdio.h>
#include <stdlib.h>

void clear(){
  printf("\x1b[2J");
}

int main(int argc, char **argv){
  clear();
  if(argc != 3){
    return 1;
  }
  int rows = strtol(argv[1],NULL,10);
  if(errno){
    return 1;
  }
  int cols = strtol(argv[2],NULL,10);
  if(errno){
    return 1;
  }
  return 0;
}



