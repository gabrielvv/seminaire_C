#include <stdio.h>


int calc(int, int);
int compars(char*, char*);
int length(char *);
int main(int argc,char** argv){


  char *ville[11]= {"Brest","Grenoble","Lille","Lyon","Marseille","Nantes","Paris","Rennes","Rouen","Strasbourg","Toulouse"};
  int ville1 = 0, ville2=0;
  if(3 != argc){
    printf("Nombre de param\212tres insuffisant");
    return 1;
  }
  int taille;
  taille = length(argv[1]);
  int j,i;
  char temp[taille+1];
  for(j=0; j < taille; j++ ){
    temp[j] = argv[1][j];


  }
  temp[taille]='\0';


  taille = length(argv[2]);
  char temp2[taille+1];
  for(j=0; j < taille; j++ ){
    temp2[j] = argv[2][j];
  }
  temp2[taille]='\0';


  for(j=0; j<11 ;j++){
        if(1 == compars(ville[j],temp)){
            ville1 = 1;
            break;
  }
}
    for(i=0; i<11 ;i++){
        if(1 == compars(ville[i],temp2)){
            ville2=1;
            break;
  }
}
  if (ville1 == 1 && ville2 ==1){
    printf("%d",calc(j,i));
  }


  else
    printf("-1");


  return 0;
}


int calc(int x, int y){
      int distance[11][11] ={
  {0, 996, 723, 890, 1286, 305, 564, 245, 424, 1026, 884},
  {-1, 0, 750, 104, 286, 711, 576, 747, 590, 505, 543} ,
  {-1, -1, 0, 668, 979, 593, 224, 515, 194, 534, 905},
  {-1, -1, -1, 0, 316, 607, 472, 645, 502, 434, 467},
  {-1, -1, -1, -1, 0, 890, 769, 938, 757, 750, 400,},
  {-1, -1, -1, -1, -1, 0, 386, 106, 315, 832, 559},
  {-1, -1, -1, -1, -1, -1, 0, 348, 112, 447, 681},
  {-1, -1, -1, -1, -1, -1, -1, 0, 249, 799, 665},
  {-1, -1, -1, -1, -1, -1, -1, -1, 0, 497, 665},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 901},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0}


};
if(distance[x][y] == -1){
    return distance[y][x];
}
else
    return distance[x][y];



}
int length(char *t)
{
int taille = 0;


	do{
    taille ++;
	}while(t[taille] != '\0');


	return taille;
}


int compars(char* ville, char*temp){
    int i,check = 1;
    for(i=0 ; i<4;i++){
        if (ville[i]!= temp[i]){
            i=4;
            check = 0;
        }
    }
    return check;
}
