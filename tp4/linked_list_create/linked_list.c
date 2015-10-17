#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
/* Implements your functions here.*/

t_maillon* new_maillon(int data){
  t_maillon *t;
  t = malloc(sizeof(t_maillon));
  t->data = data;
  t->next = NULL;
  return t;
}

unsigned int linked_list_size(t_maillon* t){
  //printf("getSize\n");
  if(t == NULL) return 0;
  unsigned int size = 1;
  t_maillon* new_t;
  new_t = t;
  while(new_t->next !=  NULL){
    size++;
    new_t = new_t->next;
  }
  return size;
}

int linked_list_get_by_position(t_maillon* t, unsigned int pos, int* find){
  //printf("ok1\n");
  int i;
  t_maillon* new_t;
  new_t = t;
  unsigned int size = linked_list_size(new_t);
  if(pos < size && pos >= 0){
    for(i = 0; i < pos; i++){
      //printf("boucle\n");
      new_t = new_t->next;
    }
    //printf("ok2\n");
    *find = 1;
    return new_t->data;
  }else{
    *find = 0;
    return 0;
  }
}

int linked_list_get_by_value(t_maillon* t, int value){
  t_maillon* new_t;
  new_t = t;
  int pos = 0;

  while(new_t->data != value){
    pos++;
    new_t = new_t->next;
    if(new_t ==  NULL){
      return (-1);
    }
  }
  return pos;
}

void linked_list_display(t_maillon* t){
  t_maillon* new_t;
  new_t = t;

  do{
    printf("%d ", new_t->data);
  }while((new_t = new_t->next) != NULL);
}

void linked_list_free(t_maillon** t){
  t_maillon** address = t;
  t_maillon* new_t = *t;

  while((new_t = new_t->next) != NULL){
    free(*address);
    address = &new_t;
  }

  free(*address);

}
