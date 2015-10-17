#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){


if (2>argc)
{
    printf("Nombre de paramètres insuffisants");
    return 1;
}
int value = atoi(argv[1]);
if(2==argc)
{
    printf("%d", fib(value));
}
else if(3==argc)
{
    int value2 = atoi(argv[2]);
    int i;
    for(i=value;i<=value2;i++)
    {
       printf("%d ", fib(i));
    }
 }
return 0;
}
int fib(int n){
  if (n < 2)
    return n;
  else
    return fib(n-1) + fib(n-2);
}
