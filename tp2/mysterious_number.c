#include <stdio.h>
#include <stdlib.h>

int puiss(int, int);

int main(int argc, char** argv){

  if (3 != argc){
      printf("Nombre de paramètres insuffisants\n");
      return 1;
    }

  int exposant = atoi(argv[1]);
  int limit = atoi(argv[2]);
  int i, temp;


  for(i=0;i<=limit;i++)
  {
    int unite = (temp = i)%10;
    int dizaine = (temp /= 10)%10;
    int centaine = (temp /= 10)%10;
    int millier = (temp /= 10)%10;
    //printf("%d %d %d %d\n", unite, dizaine, centaine, millier);
    int result = puiss(exposant,unite)+puiss(exposant,centaine)+puiss(exposant,millier)+puiss(exposant, dizaine);
    if(result == i)printf("%d ",i);
  }
  return 0;
}

int puiss(int n, int p){

  int operande = p;
  if(0 == n) return 1;
  else if(n < 0){
    while(n < -1){

      p *= operande;
      n++;
    }
      return (1/p);
  }else{
    while(n > 1){

      p *= operande;
      n--;
    }
    return (p);
  }
}
