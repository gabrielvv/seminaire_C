#include <stdio.h>

int main(int argc, char** argv){

  if (argc != 4) {
    printf("Nombre de parametre insuffisant\n");
    return 1;
  }
  int values[argc-1];

  int i;
  for(i = 0; i < argc; i++){
    values[i] = atoi(argv[i+1]);
  }

  if(values[0] < values[1]){
    if(values[0] < values[2]){
      if(values[1] < values[2]){
        printf("%d %d %d",values[0], values[1], values[2]);
      }
    }
 }else if(values[0] < values[2]){
     printf("%d %d %d",values[1], values[0], values[2]);
 }else{
   printf("%d %d %d",values[1], values[2], values[0]);
 }
  return 0;
}
