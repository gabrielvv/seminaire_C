#include <stdio.h>
#include <stdlib.h>


int length(char *t)
{
int taille = 0;


	do{
    taille ++;
	}while(t[taille] != '\0');


	return taille;
}


int main(int argc, char** argv){
  if (2 > argc) {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }


  char *value = argv[1];
  int taille;


  taille = length(value);


  printf("%d\n", taille);
  return 0;
}
