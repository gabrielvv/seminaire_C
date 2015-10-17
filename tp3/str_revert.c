#include <stdio.h>
#include <stdlib.h>


void str_revert(char *input)
{
    int taille = 0;
    int i;


	do{
    taille ++;
	}while(input[taille] != '\0');


	for (i=1;i<=taille;i++)
        printf("%c",input[taille-i]);


}


int main(int argc, char** argv){
  if (2 != argc) {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }


 str_revert(argv[1]);



  return 0;

}
