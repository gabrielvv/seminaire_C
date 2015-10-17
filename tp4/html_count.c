#include <stdio.h>

/*
** arr1, the array to perform.
*/
int html_count(char *c);
void toNextChar(char* c, int* index);
int is_html(char* c, int* index, int max);
int length(char *t);

int main(int argc, char** argv){
  if(argc != 2){

      printf("Nombre de parametres insuffisants\n");
      return 1;

  }
  printf("resultat: %d\n", html_count(argv[1]));
  return 0;
}

/*
* Compter le nombre de caractères visibles à l'intérieur d'une balise html
* Les espaces aux extrémités ne sont pas comptabilisés et un espace interne vaut 1 quelque soit sa largeur
*/

int html_count(char* html){

    printf("html_count recupere: %s\n", html);

    int min, index, max, compte;
    compte = min = index = 0;
    do{
      min++;
    }while(html[min] != '>');
    min++;
    printf("min: %d\n", min);

    max = length(html);
    do{
      max--;
    }while(html[max] != '<');
    printf("max: %d\n", max);

    int minStripSpace = min;
    do{
      minStripSpace++;
    }while(html[minStripSpace] == ' ');
    printf("minStripSpace: %d => %c\n", minStripSpace, html[minStripSpace]);

    int maxStripSpace = max;
    do{
      maxStripSpace--;
    }while(html[maxStripSpace] == ' ');
      printf("maxStripSpace: %d => %c\n", maxStripSpace, html[maxStripSpace]);

    for(index = minStripSpace; index < maxStripSpace+1; index++){
      printf("%c, index=%d\n",html[index], index);
      if(html[index] == '&'){
        compte += is_html(html, &index, maxStripSpace);
      }else if(html[index] == ' '){
        printf("espace\n");
        compte++;
        toNextChar(html, &index);
      }
      else{
        compte++;
      }
    }

    return compte;
}

void toNextChar(char* c, int* index){
  printf("toNextChar\n");
  int i;
  i = *index;
  do{


    *index = ++i;
    //*(index++);

  }while(c[i] == ' ');
  printf("next index: %d\n", *index);
  *index = i-1;
}

int is_html(char* c, int* index, int max){

  int i, limit;
  int fakeIndex = *index;
  printf("is_html recupere: %s\n", c);

  limit = ((fakeIndex+10 - max) > 0 ? max : fakeIndex+10);
  printf("limite de la recherche a l'index %d\n", limit);
  for(i = fakeIndex; i <= limit; i++){
    if(c[i] == ';'){
      *index = i;
      printf("saut de %d char\n",i-fakeIndex);
      return 1;
    }
  }
  return 1;
}

int length(char *t)
{
    int taille = 0;
    do
    {
        taille ++;
    }
    while(t[taille] != '\0');
    return taille+1;
}
