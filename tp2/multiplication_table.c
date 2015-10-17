#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){


    if (argc != 3) {
        printf("Nombre de paramètres insuffisants\n");
        return 1;
    }
    int value1 = atoi(argv[1]);
    int value2 = atoi(argv[2]);
    int i,j;


    if (value1 == value2){
    printf("%d",(value1*value2));
    }
    else if (value1<value2){
           for(i=value1;i<=value2;i++){
                for(j=value1;j<=value2;j++)
                    printf(" %d ",(i*j));
                printf("\n");
           }
       }else
       {
           for(i=value1;i>=value2;i--){
                for(j=value1;j>=value2;j--)
                    printf(" %d ",(i*j));
                printf("\n");
           }


       }
    return 0;
    }
