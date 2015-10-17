
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
  if (3 > argc) {
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
    float nb = atoi(argv[1]);
    int exponent = atoi(argv[2]);
    int i =0;
    float result = nb;
    if (exponent > 0){
        for (i = 1 ; i< exponent; i++){
            result = result*nb;
        }
        printf("%0.0f",result);
    }
    if (nb == 0 && exponent == 0){
        printf("indefinie");
    }


    if (exponent == 0 && nb!=0){
        result = 1;
        printf("%0.0f",result);
    }
    if (exponent<0){
        for (i=exponent; (i+1) < 0 ; i++){
            result = result * nb;
        }
        result = 1 / result;
        printf("%f",result);
    }


    return 0;
}
