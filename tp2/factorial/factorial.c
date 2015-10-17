#include <stdio.h>
#include <stdlib.h>

unsigned long long facto(int n);

int main(int argc, char** argv){

    int n;

    if(argc != 2){
      printf("Nombre de parametres insuffisants\n");
      return 1;
    }else if((n = atoi(argv[1])) < 0){
      printf("%d n'est pas un entier naturel\n", n);
      return 1;
    }

    printf("%llu", facto(n));
    return 0;
}

unsigned long long facto(int n){
  if(n > 1){ return (facto(n-1)*n);}
  else{ return (1);}
}
