#include <stdio.h>
#include "linked_list.h"

int main(int argc, char** argv) {

  t_maillon* list = new_maillon(4);
  list->next = new_maillon(19);
  list->next->next = new_maillon(2);
  list->next->next->next = new_maillon(7);

  int found;

  printf("Taille liste : %u \n", linked_list_size(list));
  printf("Valeur position 2 : %d \n", linked_list_get_by_position(list, 2, &found));
  printf("Position valeur 19: %d \n", linked_list_get_by_value(list, 19));

  linked_list_display(list);
  linked_list_display(list);
    printf("Valeur position 2 : %d \n", linked_list_get_by_position(list, 2, &found));
      printf("Valeur position 3 : %d \n", linked_list_get_by_position(list, 3, &found));
      printf("Position valeur 7: %d \n", linked_list_get_by_value(list, 7));
  linked_list_free(&list);
  return 0;
}
