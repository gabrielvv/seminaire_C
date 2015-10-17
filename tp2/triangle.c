#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){


  if (argc != 2) {
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
  int value1 = atoi(argv[1]);
  int i,j;



  for (i=0;i<value1;i++){
     for (j=0;j<=value1-(i+1);j++)printf (" ");
        for (j=0;j<2*i+1;j++)printf ("*");
           for (j=0;j<=value1-(i+1);j++)printf (" ");
     printf ("\n");
  }


  return 0;

}
