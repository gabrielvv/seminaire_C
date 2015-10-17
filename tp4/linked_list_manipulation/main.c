#include <stdio.h>
#include "linked_list.h"

int main(int argc, char** argv) {

  t_maillon* list = NULL;
  linked_list_append(&list, 50);
  linked_list_insert(&list, 0, 5);
  linked_list_insert(&list, 1, 8);
  linked_list_insert(&list, 2, 9);
  linked_list_insert(&list, linked_list_size(list), 10);
  linked_list_append(&list, 20);
  linked_list_size(list);
  linked_list_display(list);

  linked_list_remove_indice(&list, 0);
  linked_list_size(list);
  linked_list_display(list);

  linked_list_remove_value(&list, 20);
  linked_list_size(list);
  linked_list_display(list);

  linked_list_remove_all(&list, 8);
  linked_list_size(list);
  linked_list_display(list);

  return (0);
}
