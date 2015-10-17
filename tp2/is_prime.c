#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
      if (2 > argc) {
        printf("Nombre de paramètres insuffisants\n");
        return 1;
      }


        int value1 = atoi(argv[1]);


        if (value1 == 0 || value1==1){
            printf("0");
            return 1;
        }
        int i, compter, test;
      test = compter = 0;


      for (i = 2; i < value1; i++, compter++)
        if (value1 % i == 0)
          test = 1;
      if (!test)
        printf ("1");
      else
        printf ("0");
      return 0;
}
