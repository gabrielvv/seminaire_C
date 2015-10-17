void quickSort(int* p, int debut, int fin){
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


}
