#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
if (2 > argc){
    printf("Nombre de paramètres insuffisants\n");
    return 1;
  }
int n = atoi(argv[1]);
int reverse = 0, temp;
temp = n;
while( temp != 0 )
{
    reverse = reverse * 10;
    reverse = reverse + temp%10;
    temp = temp/10;
}


if ( n == reverse )
    printf("1");
else
    printf("0");


return 0;
}
