#include <stdio.h>

int str_search(char *string, char *pattern);

int main(int argc, char** argv){

  if (argc != 3)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }

  printf("%d", str_search(argv[1], argv[2]));
  return 0;
}

int str_search(char *string, char *pattern){

  const DEDANS = 1;
  const DEHORS = 0;

  int i, j,tailleS, tailleP, mots, nbrChar, etat, trouve;
  tailleS = tailleP = mots = nbrChar = etat = trouve = 0;

  do{
    tailleS++;
  }while(string[tailleS] != '\0');

  do{
    tailleP++;
  }while(pattern[tailleP] != '\0');

  for(i = 0; i < tailleS; i++){

      int c = string[i];

      if((c >= ' ' && c <= '/') || (c >= '{' && c < 128 || c >= '[' && c <= 96)){
        etat = DEHORS;

      }else if(c >= '0' && c <= 'Z' || c >= 'a' && c <= 'z'){
        if(etat == DEHORS)
          mots++;
        etat = DEDANS;
      }

      for(j = 0; j < tailleP; j++){

          if(string[i+j] != pattern[j]){
            trouve = 0;
            break ;
          }else{
          trouve = 1;
          }

      }
      if(trouve){
        return mots;
      }


  }
  return -1;
}
