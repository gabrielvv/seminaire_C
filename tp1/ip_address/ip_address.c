#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc != 2) {
    printf("Nombre de parametres insuffisant\n");
    return 1;
  }


  unsigned long ul;
  unsigned long ip1, ip2, ip3, ip4;
  unsigned long mask, temp;
  mask = 0xFF000000;

  ul = strtoul(argv[1], NULL, 0);
  //printf("%lu",ul);

  temp = ul;
  ip1 = temp >> 24;
  mask = 0x000000FF;
  temp = ul;
  ip2 = (temp >> 16) & mask;

  mask = 0x0000FF00;
  ip3 = ul & mask;
  mask = 1023;
  mask = 0x000000FF;
  ip4 = ul & mask;
  printf("%lu.%lu.%lu.%lu",ip1,ip2,ip3,ip4);



  return 0;
}
