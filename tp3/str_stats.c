#include <stdio.h>

/*
** Print stats to the stdout.(printf)
** input : the string to analyse
** return nothing.
*/

void str_stats(char* input) ;

int main(int argc, char** argv){
  if (2 != argc)
  {
    printf("Nombre de parametres insuffisants\n");
    return 1;
  }

  str_stats(argv[1]);

  return 0;
}

void str_stats(char *arg){

  const DEHORS = 0;
  const DEDANS = 1;
  enum voyellesMaj { A = 65, E = 69, I = 73, O = 79, U = 85, Y = 89};
  enum chiffres {ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF};
  enum consonnes {B = 66, C = 67, D = 68, F = 70, G = 71, H = 72, J = 74, K = 75, L = 76, M = 77, N = 78, P = 80, Q = 81, R = 82, S = 83, T = 84, V = 86, W = 87, X = 88, Z = 90};

  int i, j, g, taille, tailleV, tailleCo, tailleCh, etat, mots, voyelles, consonnes, chiffres;
  etat = mots = voyelles = consonnes = chiffres = 0;
  taille = tailleCo = tailleCh = 0;
  //int taille = (sizeof arg / sizeof arg[0]);

  //printf("taille : %d\n", taille);

  int tabv[12] = {A,E,I,O,U,Y};
  int tabco[21] = {B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Y, Z};
  int tabch[10] = {ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF};

  do{
    taille++;
  }while(arg[taille] != '\0');


  for(i = 0; i < taille; i++){

    int c = arg[i];
    if((c >= ' ' && c <= '/') || (c >= '{' && c < 128 || c >= '[' && c <= 96)){

      etat = DEHORS;
    }
    else if(c >= '0' && c <= 'Z' || c >= 'a' && c <= 'z'){
      if(etat == DEHORS)
        mots++;

      etat = DEDANS;

      for(j = 0; j < 12; j++){
        (c == tabv[j]) ? voyelles++ : 0 ;
        (c == (tabv[j]+32)) ? voyelles++ : 0 ;
      }
      for(j = 0; j < 21; j++){
        (c == tabco[j]) ? consonnes++ : 0 ;
        (c == (tabco[j]+32)) ? consonnes++ : 0 ;
      }
      for(j = 0; j < 10; j++){
        (c == (tabch[j]+48)) ? chiffres++ : 0 ;
      }
    }
  }

  printf("%d mot(s)\n", mots);
  printf("%d consonnes(s)\n", consonnes);
  printf("%d voyelle(s)\n", voyelles);
  printf("%d chiffre(s)", chiffres);
}
