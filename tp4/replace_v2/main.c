#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(int argc, char** argv)
{
  t_maillon* list = new_maillon(4);
   linked_list_append(&list, 12);
  linked_list_insert(&list, 0, 7);
  linked_list_insert(&list, 1, 5);
  linked_list_insert(&list, 2, 12);

  linked_list_insert(&list, linked_list_size(list), 5);
  linked_list_append(&list, 7);
  linked_list_size(list);
  linked_list_display(list);
  linked_list_remove_indice(&list, 0);
  linked_list_size(list);
  linked_list_display(list);
  linked_list_remove_value(&list, 12);
  linked_list_size(list);
  linked_list_display(list);
  //linked_list_remove_all(&list, 5);


  return (0);
}
