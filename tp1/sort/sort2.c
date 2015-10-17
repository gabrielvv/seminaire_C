#include <stdio.h>

int main(int argc, char** argv){
  if (argc == 1) {
    printf("Nombre de parametre insuffisant\n");
    return 1;
  }
  int values[argc-1];

  for(int i = 1, i < argc-1, i++){
    for(int j = 1, j < argc-i, j++ ){

      int value = argv[i];
      if(argv[])



    }
  }
  int value = atoi(argv[1]);
  if((value % 2) == 0){
    printf("0");
  }
  else{
    printf("1");
 }
  return 0;
}
