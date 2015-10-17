#include <stdio.h>
#include "abr.h"

int main(int argc, char** argv){

	t_node *Arbre = NULL;

  abr_insert(&Arbre, 1);
  abr_insert(&Arbre, 2);
  abr_insert(&Arbre, 3);
  abr_insert(&Arbre, 4);
  abr_insert(&Arbre, 10);
  abr_insert(&Arbre, 5);

  abr_insert(&Arbre, 7);
  abr_insert(&Arbre, 8);
  abr_insert(&Arbre, 9);
  abr_insert(&Arbre, 6);
  abr_display_asc(Arbre);

  return 0;

}
