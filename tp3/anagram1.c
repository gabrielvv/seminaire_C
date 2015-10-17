#include <stdio.h>

/*
** s1, s2 : the string to evaluate.
** return 0 if false, 1 if true.
*/
short is_anagram(char* s1, char* s2);
void sort(char*, int, int);
/*
** s1 : the string to perfom.
** print anagrams to stdout (printf())
** return void.
*/
void display_anagrams(char* s1);

int main(int argc, char** argv){

  if (argc < 2)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }
  display_anagrams(argv[1]);

}

void display_anagrams(char* s1){

  int taille = 0;

  do{
    taille++;
  }while(s1[taille] != '\0');

  sort(s1, taille, 0);
}

void sort(char* string, int taille, int decalage){

  printf("%s", string);
  int i;
  char* temp;
  if(taille == 1){
    printf("%s",string);
  }else{
    temp = string+taille-1;
    for(i = 0; i < taille-1; i++)
      string = string+i;

    string = temp;
    sort(string, taille-1, ++decalage);
  }
}
