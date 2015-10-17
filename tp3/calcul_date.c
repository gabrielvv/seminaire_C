
#include <stdio.h>
#include <stdlib.h>


int dayNumber(int, int, int);
int isLeapyear(int);


int main(int argc,char** argv){
  int annee,mois,jour,i,j;


  if(2 != argc){
    printf("Nombre de param\212tres insuffisant");
    return 1;
  }
  char tempannee[5];
  char tempmois[3];
  char tempjour[3];
    for(j=0; j < 4; j++ ){
      temp[j] = argv[1][j];
      //printf("%c", temp[j]);
    }
    for(j=0; j < 2 ; j++ ){
      tempmois[j] = argv[1][j+4];
      //printf("%c\n", tempmois[j]);
    }
    for(j=0; j < 2 ; j++ ){
      tempjour[j] = argv[1][j+6];
      //printf("%c\n", tempmois[j]);
    }
    temp[5]='\0';
    tempmois[2]='\0';
    tempjour[2]='\0';
    annee = atoi(temp);
    mois = atoi(tempmois);
    jour = atoi(tempjour);
    printf("%d",dayNumber(annee,mois,jour)) ;
    return 0;
    }



int dayNumber(int annee, int mois, int jour){
    int tp = 0;


    switch(mois-1){
    case 12 : tp += 31;
    case 11 : tp += 30;
    case 10 : tp += 31;
    case 9 : tp += 30;
    case 8 : tp += 31;
    case 7 : tp += 31;
    case 6 : tp += 30;
    case 5 : tp += 31;
    case 4 : tp += 30;
    case 3 : tp += 31;
    case 2 : tp += isLeapyear(annee);
    case 1 : tp += 31;
    break;
    }
    tp += jour ;
    return tp;
}


int isLeapyear(int annee){
 int fevrier = 28;
 if ((annee%4 == 0 && annee%100 != 0 ) || (annee % 400 == 0)){
    fevrier = 29;
 }
 return fevrier;
}
