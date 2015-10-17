#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){

  int i,j;
  if(3 != argc){
    printf("Nombre de param\212tres insuffisant");
    return 1;
  }else if( atoi(argv[1]) < 0 || atoi(argv[2]) < 0){
    printf("Division sur des entiers naturels uniquement");
    return 1;
  }else if(0 == atoi(argv[2])){
    printf("Division par zero impossible");
    return 1;
  }else if( (i = atoi(argv[1])) < (j = atoi(argv[2])) ){
    printf("%d n'est pas divisible par %d", i, j);
    return 1;
  }

  int divisor = atoi(argv[2]), dividend = atoi(argv[1]), remainder = dividend, quotient = 0;
  i = 0;
  while((remainder -= divisor) >= 0)
    quotient++;

  if((remainder += divisor) == 0)
    printf("%d=%d*%d", dividend, quotient, divisor);
  else
    printf("%d=%d*%d+%d", dividend, quotient, divisor, remainder);

  return 0;
}
