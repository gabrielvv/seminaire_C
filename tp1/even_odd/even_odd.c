#include <stdio.h>

int main(int argc, char** argv){
  if (2 > argc || 2 < argc) {
    printf("Il faut 1 parametre\n");
    return 1;
  }
  int value = atoi(argv[1]);
  if((value % 2) == 0){
    printf("0");
  }
  else{
    printf("1");
 }
  return 0;
}
