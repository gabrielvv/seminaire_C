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
    int splitPresent = FALSE;
    int i,split,j, del;
    unsigned int array1_length;
    del = 0;//pour comptabiliser les doublons
    //int * tab;
	//tab = calloc(argc-2,sizeof(int));
    for(i=1 ; i<argc; i ++){
        if (*argv[i] == '-'){
            split = i;
            splitPresent = TRUE;
            break;
        }
        else{
          split = 0;
        }
    }
    //printf("Split: %d\n",split);
    int * arr1, * arr2;
    (split > 0) ? (arr1 = calloc(split-1,sizeof(int))) : (arr1 = NULL) ;
    arr2 = calloc((argc-1)-split,sizeof(int));

    array1_length = 0;
    for(j= 1 ; j<split;j++){
       arr1[j-1] = atoi(argv[j]);
       array1_length++;
       //printf("Element tab1: %d\n", arr1[j-1]);
    }


    for(j=split+1; j < argc ;j++){
        arr2[j-(split+1)] = atoi(argv[j-del]);
        //printf("Element tab2: %d\n",arr2[j-(split+1)]);
    }


    //int array1_length = sizeof(arr1);
    //array1_length = tabLength(arr1);
    //printf("array1_length = %d\n", array1_length);

    unsigned int length;
    length = (splitPresent ? argc-2-del: argc-1-del);

    int* result = array_merge(arr1,arr2,array1_length,&length);
    for (i=0; i<length;i++)
      printf("%d ", *(result+i));
    free(result);

  return 0;
}

int* bubbleSort(int* tab, int taille){

  //int taille = sizeof p/sizeof p[0];
  //printf("taille tab: %d\n", taille);
  int i, j;
  int* address = tab;
  for(i = 0; i < taille; i++){
    //printf("%d\n", *tab);
    for(j = 0; j < taille-1; j++){

      int* inf = tab;
      int* sup = tab+1;
      int a, b;
      a = *inf;
      b = *sup;
      //printf("inf: %d sup: %d\n", *inf, *sup);
      if(a > b){
        permuter(inf, sup);
      }
      tab++;
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

  int* tab;
  //printf("taille: %d\n",*length);
	tab = calloc(*length,sizeof(int));
	int i,j=0, k;
	for(i=0; i < *length+1;i++){
        if(i < arr1_length ){
            tab[i] = arr1[i];
        }
        else{
            //printf("arr2[j]: %d\n", arr2[j]);
            tab[i] = arr2[j];
            j++;
        }
      //printf("Element: %d\n",tab[i]);
	}
  tab = bubbleSort(tab, *length);

  j = 0;
  for(i=0 ; i < ((*length)-1) ; i++){
    if(tab[i] == tab[i+1]){
      for(k = i ; k < ((*length)-1);k++){
        tab[k] = tab[k+1];
        j = 1;
      }
      i--;
    }


    if(j == 1){
      *length -= 1;
      j = 0;
    }
  }

  return tab;
}
