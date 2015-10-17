#include <stdio.h>
#include <stdlib.h>

/*
** arr1, arr2 : the arrays to merge.
** a new sorted array with value merged from arr1, arr2
** arr1_length : length of the first array.
** lentgh : countains size of the new array
** if arr1 and arr2 owns sames keys, arr2 wons.

*/
int* array_merge(const int* arr1, const int* arr2, unsigned int arr1_length, unsigned int* length);
void bubblesort(int* p, int taille);
void permuter(int* a, int* b);

int main(int argc, char** argv){

  int i;
  int tab[argc-1];
  //printf("taille tab: %d\n", argc-1);
  for(i = 1; i < argc; i++){
    tab[i-1] = atoi(argv[i]);
    printf("%d\n", tab[i-1]);
  }
  bubblesort(tab, argc-1);
  return 0;
}

void bubblesort(int* p, int taille){

  //int taille = sizeof p/sizeof p[0];
  //printf("taille tab: %d\n", taille);
  int i, j;
  int* address = p;
  for(i = 0; i < taille-1; i++){
    //printf("%d\n", *p);
    for(j = 0; j < taille-i; j++){

      int inf = *p;
      p++;//j'incrémente mon pointeur
      int sup = *p;
      //printf("inf: %d sup: %d\n", inf, sup);
      if(inf > sup){
        permuter(p--, p);
      }
    }
    p = address;
  }

  for(i = 0; i < taille; i++)
    //printf("%d ", p[i]);
}

int length(int *t)
{
    int taille = 0;
    do
    {
        taille ++;
    }
    while(t[taille] != '\0');
    return taille+1;
}


void permuter(int* a, int* b){
  //printf("permuter: a=%d et b=%d\n", *a, *b);
  int temp = *a;
  *a = *b;
  *b = temp;
  //printf("a=%d et b=%d\n", *a, *b);
}

/*
int i;
unsigned int length;

int* result = array_merge(arr1, arr2, arr1_length, &length);
for (i=0; i<length;i++)
  printf("%d ", *(result+i));
free(result);*/


/*
void quicksort(int* p, int debut, int fin){
if(debut < fin)
  int index;
  int pivot = *p;
  printf("pivot: %d", pivot);

  int tailleGauche = 0, tailleDroite = 0;

  for(index = debut+1; index <= fin; index++){
    if(p[index] <= pivot){
      tailleGauche++;
    }else{
      tailleDroite++;
    }
  }

  int tabG[tailleGauche+1];
  int tabD[tailleDroite];

  int i = 0;
  int j = 0;

  for(index = debut+1; index <= fin; index++){
    if(p[index] <= pivot){
      tabG[i];
      i++;
    }else{
      tabD[j];
      j++;
    }
  }


}*/
