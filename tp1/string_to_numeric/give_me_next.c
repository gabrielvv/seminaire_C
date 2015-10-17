#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (2 > argc) {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }
  int value = atoi(argv[1]);
  printf("Entier suivant : %i \n", ++value);
  return 0;
}
