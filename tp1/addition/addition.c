#include <stdio.h>

int main(int argc, char** argv){
  if (argc == 2 || argc > 3) {
    printf("Il faut 2 parametres\n");
    return 1;
  }
  printf("%d", (atoi(argv[1])+atoi(argv[2])));
  return 0;
}
