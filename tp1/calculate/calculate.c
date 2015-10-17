#include <stdio.h>

int main(int argc, char** argv){

  if (argc != 4) {
    printf("expression invalide\n");
    return 1;
  }
  int value1 = atoi(argv[1]);
  int value2 = atoi(argv[3]);
  char operateur = *argv[2];
 
  if(operateur == '+'){
    int result = value1 + value2;
    printf("%d",result);
  }
  else if(operateur == '-'){
    int result = value1 - value2;
    printf("%d",result);
  }else if(operateur == '/'){
    if(value2 == 0){
      printf("expression invalide\n");
      return 1;
    }
    int result = value1 / value2;
    printf("%d",result);
  }else if(operateur == '*'){
    int result = value1 * value2;
    printf("%d",result);
  }else if(operateur == '%'){
    int result = value1 % value2;
    printf("%d",result);
  }else{
    printf("expression invalide\n");
    return 1;
  }
  return 0;
}
