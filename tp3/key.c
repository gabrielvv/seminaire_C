#include <stdio.h>
#include <stdlib.h>

char key(int value)
{
    char T[4];
    int i;
    char result;

    for(i=0; i<4; i++)
    {
        T[i] = value%10;
        value /= 10;
    }

    T[3] *= 3;
    T[2] *= 7;
    T[1] *= 11;
    T[0] *= 13;

    result = ((T[0]+T[1]+T[2]+T[3])%26)+65;
    return result;
}

int main(int argc, char** argv){
  if (2 != argc)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }

  int input = atoi(argv[1]);
  if(input > 9999 || input < 1000)
  {
      printf("incorrect\n");
    return 1;
  }

  printf("cle : %c", key(input));
 return 0;
}
