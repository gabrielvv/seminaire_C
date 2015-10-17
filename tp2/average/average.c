#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){

  if(1 == argc){
    printf("Nombre de param\212tres insuffisant\n");
    return 1;
  }

  int i;
  float total = 0;
  for(i = 1; i < argc; ++i){
    total += atof(argv[i]);
  }

  printf("%.1f", total/(argc-1));
  return 0;
}
