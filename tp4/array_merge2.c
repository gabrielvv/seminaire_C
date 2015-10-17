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
int* bubbleSort(int* p, int taille);
void permuter(int* a, int* b);

int main(int argc, char** argv){

    enum boolean {FALSE, TRUE};
    int copy = TRUE;
    int i,split,j, array1_length, del;
    del = 0;//pour comptabiliser les doublons
    //int * tab;
	//tab = calloc(argc-2,sizeof(int));
    for(i=1 ; i<argc; i ++){
        if (*argv[i] == '-'){
            split = i;
        }
    }
    printf("Split: %d\n",split);
    int * arr1, * arr2;
    arr1 = calloc(split-1,sizeof(int));
    arr2 = malloc((sizeof(int));

    array1_length = 0;
    for(j= 1 ; j<split;j++){
       arr1[j-1] = atoi(argv[j]);
       array1_length++;
       printf("Element tab1: %d\n", arr1[j-1]);
    }


    for(j=split+1; j < argc ;j++){
        for(i=0; i < array1_length; i++){
          if(arr1[i] == atoi(argv[j])){
            copy = FALSE;
            break;
          }else{
            copy = TRUE;
          }
        }
      if(copy){
        arr2[j-(split+1)] = atoi(argv[j-del]);
        //arr2++ = malloc((sizeof(int));
        printf("Element tab2: %d\n",arr2[j-(split+1)]);
      }else{
        del++;//une case vide en plus à la fin du tableau
      }
    }


    //int array1_length = sizeof(arr1);
    //array1_length = tabLength(arr1);
    printf("array1_length = %d\n", array1_length);
    int length = argc-2-del;

    int* result = array_merge(arr1,arr2,array1_length,&length);
    for (i=0; i<length;i++)
      printf("%d ", *(result+i));
    free(result);


}

int* bubbleSort(int* tab, int taille){

  //int taille = sizeof p/sizeof p[0];
  //printf("taille tab: %d\n", taille);
  int i, j;
  int* address = tab;
  for(i = 0; i < taille-1; i++){
    //printf("%d\n", *p);
    for(j = 0; j < taille-i; j++){

      int inf = *tab;
      tab++;//j'incrémente mon pointeur
      int sup = *tab;
      //printf("inf: %d sup: %d\n", inf, sup);
      if(inf > sup){
        permuter(tab--, tab);
      }
    }
    tab = address;
  }
  return tab;
}

void permuter(int* a, int* b){
  //printf("permuter: a=%d et b=%d\n", *a, *b);
  int temp = *a;
  *a = *b;
  *b = temp;
  //printf("a=%d et b=%d\n", *a, *b);
}

int* array_merge(const int* arr1, const int* arr2, unsigned int arr1_length, unsigned int* length){

  int * tab;
  printf("taille: %d\n",*length);
	tab = calloc(*length,sizeof(int));
	int i,j=0 ;
	for(i=0; i < *length;i++){
        if(i < arr1_length ){
            tab[i] = arr1[i];
        }
        else{
            printf("arr2[j]: %d\n", arr2[j]);
            tab[i] = arr2[j];
            j++;
        }
      printf("Element: %d\n",tab[i]);
	}
  tab = bubbleSort(tab, *length);
  return tab;
}
