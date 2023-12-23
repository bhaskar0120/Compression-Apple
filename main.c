#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void clear(){
  printf("\x1b[2J");
}

void raw(FILE* file, int rows, int cols){
  size_t readSoFar = 0;
  char* buffer = (char*)malloc(rows*cols+rows);
  char* data = (char*)malloc(rows*cols);
  for(int i = 0; i < rows; ++i){
    buffer[i*(cols+1) + cols] = '\n';
  }
  while(readSoFar < 6572){
    clear();
    size_t alreadyRead = 0;
    while(alreadyRead < rows*cols){
      alreadyRead += fread(data+alreadyRead,1,min(4096,rows*cols-alreadyRead),file);
    }

    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        buffer[i*(cols+1)+j] = (data[i*cols+j] > 200u)?'@':' ';
      }
    }
    printf("%s",buffer);
    readSoFar++; 
    Sleep(1000.0/30.0);
  }
  
  free(buffer);
  free(data);
}



int main(int argc, char **argv){
  if(argc != 2){
    return 1;
    //TODO Write argError
  }

  char* vidFile = argv[1];

  FILE *file = fopen(vidFile,"rb");
  if(errno){
    return 1;
    //TODO Write fileNotFound
  }
  int rows, cols;
  fread(&rows, 4,1,file);
  fread(&cols, 4,1,file);
  

  if(rows*cols >= 1000000){
    return 1;
    // TODO Write memSizeExceeded
  }
  raw(file,rows,cols);


  fclose(file);
  if(errno){
    return 1;
    //TODO Write fileCloseError
  }



  return 0;
}



