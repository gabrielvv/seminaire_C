#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

double puiss(int, double);

int main(int argc,char** argv){

  double result = 0, racine12 = sqrt(12);
  int i;
  if(2 != argc){
    printf("Nombre de param\212tres insuffisant");
    return 1;
  }

  float arg = atoi(argv[1]);

  for(i = 0; i < arg; i++){
    result += (puiss(-i, -3)/(2*i+1));
  }

  printf("%.6f", result*racine12);
  return 0;
}

//pour calculer p puissance n
double puiss(int n, double p){

  double operande = p;
  if(0 == n) return 1;
  else if(n < 0){

    while(n < -1){

      p *= operande;
      n++;
    }
  }

  return (1/p);

}
