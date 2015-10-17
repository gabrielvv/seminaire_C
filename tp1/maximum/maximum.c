#include <stdio.h>

int main(int argc, char** argv){
  if (argc != 3) {
    printf("Il faut 2 parametres\n");
    return 1;
  }
  int value1 = atoi(argv[1]);
  int value2 = atoi(argv[2]);
  (value1 > value2) ? printf("%d", value1) : printf("%d",value2);
  return 0;
}
