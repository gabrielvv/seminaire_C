#include <stdio.h>

void str_replace_first(char *string, char *pattern, char *replacement);

int main(int argc, char** argv){
  if (4 != argc)
  {
    printf("Nombre de param\212tres insuffisants");
    return 1;
  }

  str_replace_first(argv[1], argv[2], argv[3]);

  return 0;
}

void str_replace_first(char *string, char *pattern, char *replacement){

  int i, j, tailleS, tailleP, tailleR, trouve;
  tailleS = tailleP = tailleR = trouve = 0;

  do{
    tailleP++;
  }while(pattern[tailleP] != '\0');

  do{
    tailleR++;
  }while(replacement[tailleR] != '\0');

  if(tailleR != tailleP){
    printf("Les chaines de recherche et de remplacement ne correspondent pas");
  }else{

    do{
      tailleS++;
    }while(string[tailleS] != '\0');

    for(i = 0; i < tailleS; i++){
        for(j = 0; j < tailleP; j++){
            if(string[i+j] != pattern[j]){
              trouve = 0;
              break ;
            }else{
            trouve = 1;

            }
        }
        if(trouve){
          for(j = 0; j < tailleP; j++){
            string[i+j] = replacement[j];
          }
        }
    }
    printf("%s", string);
  }
}
