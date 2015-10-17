#include <stdio.h>


/*
** input : the string to analyse
** return 0 if false, 1 if true.
*/
short is_palindrome(char* input);

int main(int argc, char** argv){
  if (argc < 2)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }

  //is_palindrome(argv[1]);
  printf("%d", is_palindrome(argv[1]));
  return 0;
}

short is_palindrome(char* input){

  //printf("input: %s\n",input);
  int i, taille = 0, tailleSansEspace = 0;

  do{
    taille++;
  }while(input[taille] != '\0');

  //printf("taille: %d\n",taille);


  for(i = 0; i <= taille; i++){
    if(input[i] != ' '){
      tailleSansEspace++;
    }
  }

  char temp[tailleSansEspace-1];
  printf("taille: %d\n",tailleSansEspace);

  int decalage = 0;

  for(i = 0; i <= taille; i++){
    char c = input[taille-1-i];

    if(c >= 'A'  && c <= 'Z'){//conversion des majuscules en minuscules
       input[taille-1-i] = c+32;
       //printf("%c",input[taille-1-i]);
    }
    if(input[taille-1-i] != ' '){

      temp[i-decalage] = input[taille-1-i];

      //printf("%c %c\n", temp[i-decalage], input[taille-1-i]);
    }else{
      decalage++;
    }
  }

  temp[tailleSansEspace-1] = '\0';
  printf("temp: %s\n",temp);
  //printf("ok");
  for(i = 0; i < tailleSansEspace-1; i++){
    printf("%c %c\n", temp[i], temp[tailleSansEspace-2-i]);

    if(temp[i] == temp[tailleSansEspace-2-i]){

    }else{
      return 0;
    }
  }
  return 1;

}
