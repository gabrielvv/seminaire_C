#include <stdio.h>
#include <stdlib.h>

unsigned long long facto(int n);

int main(int argc, char** argv){


  if(argc != 3){
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }else if(atoi(argv[2]) == 0){
    printf("infini\n");
    return 1;
  }else{
    int a = (atoi(argv[1]) < 0 ? atoi(argv[1])*-1 : atoi(argv[1])) ;
    int b = (atoi(argv[2]) < 0 ? atoi(argv[2])*-1 : atoi(argv[2]));
    printf("%d", pgcd(a, b));
    return 0;
  }
}

int pgcd(int a, int b){

  do{
    int r = a % b;
    a = b;
    b = r;
  }while(b != 0);
  return a;
}
