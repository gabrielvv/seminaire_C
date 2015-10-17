#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){


  if (argc < 3) {
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
  unsigned int i, j;

  int ord[argc-1], absc[argc-1];
  char temp[3];

  for(i = 1; i < argc; i++){
    for(j=0; j < 3; j++ ){
      temp[j] = argv[i][j];
      //printf("%c", temp[j]);
    }
    char c[2];
    c[0] = temp[0];
    c[1] = '\0';
    absc[i-1] = atoi(c);
    c[0] = temp[2];
    c[1] = '\0';
    ord[i-1] = atoi(c);

    //printf("%d %d", absc[i-1],ord[i-1] );
  }

  //printf("%d %d %d %d", absc[0], absc[argc-2], ord[0], ord[argc-2]);
  if(absc[0] != absc[argc-2] || ord[0] != ord[argc-2]){
    printf("Le polygone n'est pas complet");
    return 1;
  }

  int maxAbsc = 0, minAbsc = 0 , maxOrd = 0, minOrd = 0;

  for(i = 0; i < argc-1; i++){
    maxAbsc = ((absc[i] > maxAbsc) ? absc[i] : maxAbsc);
    maxOrd = (ord[i] > maxOrd ? ord[i] : maxOrd);
    minAbsc = (absc[i] < minAbsc ? absc[i] : minAbsc);
    minOrd = (ord[i] < minOrd ? ord[i] : minOrd);
  }

  //printf("%i %i %i %i", maxAbsc, minAbsc, maxOrd, minOrd);
  for(i = 0; i < argc-1; i++){
    if(absc[i] < maxAbsc && absc[i] > minAbsc && ord[i] < maxOrd && ord[i] > minOrd){
      printf("2");
      return 0;
    }
  }

  printf("1");
  return 0;
}
