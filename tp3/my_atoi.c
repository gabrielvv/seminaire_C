#include <stdio.h>

int my_atoi(char *);

int main(int argc, char** argv){
  if (2 != argc)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }


  printf("%d", my_atoi(argv[1]));
  return 0;
}

int my_atoi(char *arg){

  int entier = 0, temp, i, taille = sizeof arg / sizeof arg[0];

  int sign = ((arg[0] == '-') ? -1: 1);
  (sign == -1) ? (i = 1) : (i = 0);

  int decal=i;
  for(i; i < taille-1+decal; i++){

    temp = (arg[i] - '0');

    if(temp < 10 && temp > 0){
      entier = ((entier*10)+temp);
    }else{
      return 0;
    }

  }
  return entier*sign;

}
