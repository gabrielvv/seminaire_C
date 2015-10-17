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
    //printf("bouclage size\n");
    //system("pause");
    size++;
    new_t = new_t->next;
  }
  //printf("size = %d", size);
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
  printf("\n");
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


/*Add an s_maillon at the end of the linked_list */
void linked_list_append(t_maillon** list, int data){
  //printf("list_append\n");

  t_maillon* t = *list;
  if(t == NULL){
    t = malloc(sizeof(t_maillon));
    t->data = data;
    t->next = NULL;
    *list = t;
    //printf("append pointer %p avec valeur %d\n", t, t->data);
    //system("pause");
  }else{
    t_maillon* new_t = malloc(sizeof(t_maillon));
    new_t->data = data;
    new_t->next = NULL;
    while(t->next != NULL){
      //printf("boucle append\n");
      t = t->next;
    }
    t->next = new_t;
  }
}

/*Insert at any place between 0 and linked_list_size() */
void linked_list_insert(t_maillon** list, int index, int data){
  //printf("list_insert\n");

  //printf("size %u", linked_list_size(*list));

  t_maillon* t = *list;

  if(index == 0){
    if(t == NULL){ linked_list_append(list, data);}
    else{
      t_maillon* t_insert = malloc(sizeof(t_maillon));
      t_insert->data = data;
      t_insert->next = t;
      *list = t_insert; //le nouvel élément est tête de liste pointée par list
    }
  }else if(index == linked_list_size(*list)){
    linked_list_append(list, data);
  }else if(0 < index && index < linked_list_size(*list)){

    t_maillon* t_before = *list;
    t_maillon* t_insert = malloc(sizeof(t_maillon));
    t_insert->data = data;
    int i;
    for(i = 0; i < index-1; i++){
      t_before = t_before->next;
      //printf("incrémentation insert");
    }
    //printf("insertion %p a l'index %d\n", t_insert, i+1);
    //system("pause");
      t_maillon* t_after = t_before->next;
      t_before->next = t_insert;
      t_insert->next = t_after;

    }
   }



/* Remove the s_maillon at index position, if index is in [0, linked_list_size()] */
void linked_list_remove_indice(t_maillon** list, unsigned int index){
  //printf("remove indice");
  if(index >= 0 && index <= linked_list_size(*list) && *list != NULL){
    t_maillon* t = *list;
    t_maillon* t_before = NULL;
    t_maillon* t_after = NULL;
    t_maillon* t_remove = t;
    int i;
    for(i = 0; i < index; i++){
      t_before = t_remove;
      t_remove = t_remove->next;
      t_after = t_remove->next;
    }
    if(i == 0){
      *list = t_remove->next;
    }else{

      t_before->next = t_after;
    }
    //printf("remove indice: liberation %p a l'index %d\n", t_remove, i);
    free(t_remove);
  }
}

/* Remove first s_maillon containing the data value. */
void linked_list_remove_value(t_maillon** list, int data){

    int find = 0;
    t_maillon* t = *list;
    t_maillon* t_before = NULL;
    t_maillon* t_after = NULL;
    t_maillon* t_remove = t;
    if(t_remove->data == data){
      *list = t_remove->next;
      free(t_remove);
    }else{
      while(t_remove->data != data && t_remove->next != NULL){
        t_before = t_remove;
        t_remove = t_remove->next;
        t_after = t_remove->next;
        if(t_remove->data == data)
          find = 1;
          break;
      }

      if(find){
        t_before->next = t_after;
        //printf("remove value :liberation %p de valeur %d\n", t_remove, t_remove->data);
        free(t_remove);
      }
    }
}

/* Remove all s_maillon containing the data value. */
void linked_list_remove_all(t_maillon** list, int data){
  int find = 1;
  while(find){
  t_maillon* t = *list;
  t_maillon* t_before = NULL;
  t_maillon* t_after = NULL;
  t_maillon* t_remove = t;
  if(t_remove->data == data){
    *list = t_remove->next;
    free(t_remove);
  }else{
    while(t_remove->data != data && t_remove->next != NULL){
      t_before = t_remove;
      t_remove = t_remove->next;
      t_after = t_remove->next;
      if(t_remove->data == data){
        find = 1;
        break;
      }
      else{
        find = 0;
      }
    }

    if(find){
      t_before->next = t_after;
      //printf("remove value :liberation %p de valeur %d\n", t_remove, t_remove->data);
      free(t_remove);
      }
    }
  }
}
