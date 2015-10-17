#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

void stack_push(t_my_stack** pointer_stack, int value){
  t_my_stack* new_e = malloc(sizeof(t_my_stack));//création d'un nouvel élément;
  new_e->value = value;
  new_e->pointer = *pointer_stack;

  *pointer_stack = new_e;//mise à jour de la valeur du pointeur sur stack

}

int stack_pop(t_my_stack** pointer_stack){
  //remove the next value from the stack and return it

  t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
  if(my_stack == NULL){
    return (-1);
  }else{
    int value = my_stack->value;

    *pointer_stack = my_stack->pointer;//modification de la valeur de pointeur stockée de le pointeur de pointeur (sur l'avt dernier element puisque le dernier element va être supprimé);
    free(my_stack);

    return value;
  }
}

int stack_peek(t_my_stack** pointer_stack){

  t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
  if(my_stack == NULL){
    return (-1);
  }else{

    int value = my_stack->value;
    return value;
  }
}

void free_stack(t_my_stack* stack){

  t_my_stack** pointer_stack = &stack;

  while((stack = stack->pointer) != NULL){
    free(*pointer_stack);
    *pointer_stack = stack;
  }

  free(*pointer_stack);

}
