#include <stdio.h>

int main(int argc, char** argv){
  if (3 > argc) {
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
  printf("Parametre 1 : %s \n", argv[1]);
  printf("Parametre 2 : %s \n", argv[2]);
  return 0;
}
