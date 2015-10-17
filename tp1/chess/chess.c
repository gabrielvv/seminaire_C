#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
  if (4 > argc) {
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
        int type = atoi(argv[1]);
        int verticalDepart = atoi(argv[2]);
        int horizontalDepart = atoi(argv[3]);


        char value = ((1==type)&&(((verticalDepart+horizontalDepart)%2==0)))?'B':'N';
        int verticalArrive = atoi(argv[4]);
        int horizontalArrive = atoi(argv[5]);


        char moveAxe = (((2==type)&&(2==verticalDepart-verticalArrive)||(2==verticalArrive-verticalDepart)))?'V':'H';
        char value2 =(2==type && (('V'==moveAxe&&(1==horizontalDepart-horizontalArrive)||(1==horizontalArrive-horizontalDepart))||('H'==moveAxe&&(1 ==verticalDepart-verticalArrive)||(1==verticalArrive-verticalDepart))))?'V':'I';


        (1==type)? printf("%c",value): printf("%c",value2);
    return 0;
}
