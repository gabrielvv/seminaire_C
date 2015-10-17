#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE *f_in,*f_out;
  char* ent=argv[1], *sor=argv[2];
  int c;
  // Ouverture du fichier ENTREE en lecture
  if (NULL == (f_in = fopen(ent,"r"))) {
    printf("I");
    return(EXIT_FAILURE);
  }
  if (NULL != (f_out = fopen(sor,"r"))) {
    printf("fichier %s existant, copie impossible",sor);
    return(EXIT_FAILURE);
  }
  // Ouverture du fichier SORTIE en ecriture
  if (NULL == (f_out = fopen(sor,"w"))) {
    printf("I");
    return(EXIT_FAILURE);
  }

  // Recopie du contenu de ENTREE dans SORTIE
  printf("double du fichier %s : ",ent);
  fprintf(f_out,"double du fichier %s : ",ent);
  while ((c = fgetc(f_in)) != EOF)
  {
    fputc(c, f_out);
    printf("%c",c);
  }

  // Fermeture des flots de donnees
  fclose(f_in);
  fclose(f_out);
  return(EXIT_SUCCESS);
}
