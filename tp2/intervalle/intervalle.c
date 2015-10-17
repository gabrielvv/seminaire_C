#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){


  int i;

  if(argc != 3){
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }else if((i = atoi(argv[1])) < 0){
    printf("%d n'est pas un entier naturel\n", i);
    return 1;
  }else if((i = atoi(argv[2])) < 0){
    printf("%d n'est pas un entier naturel\n", i);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  if(a <= b){
    for(i = 0; i <= (b - a); i++){
      printf("%d ",i+a);
    }
  }else{

    for(i = 0; i <= (a - b); i++){
      printf("%d ", a-i);
    }
  }
  return 0;
}
