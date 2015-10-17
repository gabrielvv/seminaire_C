#include <stdio.h>
#include <stdlib.h>

typedef struct s_my_stack {
  char* c;
  unsigned int size;
  unsigned int index;
  struct s_my_stack* pointer;
} t_my_stack;


void stack_push(t_my_stack** pointer_stack, char* value, unsigned int size, unsigned int index);
t_my_stack stack_pop(t_my_stack** stack);
t_my_stack stack_peek(t_my_stack** stack);
void free_stack(t_my_stack* stack);

int strlength(char *t);
void toNextChar(char* c, int* index, t_my_stack** stack);
short isSpecialChar(char* c, int* index, t_my_stack** stack);
void detectBaliseAndStack(char* input, int* index, t_my_stack** stack);
char* html_substring(char* input, int length, char* appender);


int main(int argc, char** argv){
  printf("%s",html_substring(argv[1], 15, "..."));
  return 0;
}
 /*
 ** char* input the html to process.
 ** int the length of the substring.
 ** char* appender, optionnal, (if not null), append this suffix to the resulting chain.
 ** /!\ if an appender is present, his length his substract from global length.
 */

char* html_substring(char* input, int length, char* appender){

   t_my_stack* stack1 = NULL;
   //t_my_stack* stack2 = NULL;
   int* index;
   index = malloc(sizeof(int));
   *index = 0;
   int compte = 0;
   char* output = NULL;
   char* stockage = malloc(sizeof(char));

  while(compte != length){
     //printf("%c, index=%d\n",html[index], index);
     if(input[*index] == '<'){
       detectBaliseAndStack(input,index,&stack1);//fait sauter l'index
     }
     if(input[*index] == '&'){
       if(isSpecialChar(input, index, &stack1)){
        compte++;
      }else{
        compte++;

        *stockage = input[*index];
        stack_push(&stack1, stockage, 1, *index);
        //fait sauter l'index si rencontre un specialChar
       //stocke specialChar si existe sinon stocke caractère courant
      }
     }else if(input[*index] == ' '){
       printf("espace\n");
       compte++;
       toNextChar(input, index, &stack1);
       //stocke un espace et fait sauter l'index au prochain caractère
     }
     else{
       compte++;
       *stockage = input[*index];
       stack_push(&stack1, stockage, 1, *index);
     }
     *index = *index+1;
   }

   int size = 0;
   t_my_stack* stack2 = stack1;
   int i, j;
   for(i = 0; i < *index; i++){
     t_my_stack stack = stack_pop(&stack1);
     size += stack.size;
   }

   *index = 0;
   output = malloc(sizeof(char)*size);
   for(*index = *index; *index < size; *index = *index+1){
     t_my_stack stack = stack_pop(&stack2);
     char* c = stack.c;
     for(j = 0; j < stack.size; j++){
       output[i+j] = c[j];
       *index  = *index+j;
     }
   }

   return output;
 }

 int strlength(char *t)
 {
     int taille = 0;
     do
     {
         taille ++;
     }
     while(t[taille] != '\0');
     return taille+1;
 }

 void detectBaliseAndStack(char* input, int* index, t_my_stack** t){
   int i = *index;
   int j = 0;

   do{
     i++;
   }while(input[i] != '>');

   int sizeBalise = i-*index+1;

   char* balise = malloc(sizeof(char)*sizeBalise);
   for(i = *index; i < sizeBalise; i++){
     if(i-(*index) == 1){
       printf("ajout / ds balise\n");
       balise[i-(*index)] = '/';
       j++;
     }else if(i-(*index) > 1){
       balise[i-(*index)] = input[*index+i-j];
       printf("%c", balise[i-(*index)]);
     }
   }
   printf("\n");

   stack_push(t , balise, sizeBalise, *index);

 }


 short isSpecialChar(char* c, int* index, t_my_stack** t){

   char* specialChar;
   int i, sizeSpecialChar;
   int fakeIndex = *index;
   printf("specialChar récupère: %s\n", c);

   for(i = fakeIndex; i < fakeIndex+9; i++){
     if(c[i] == ';'){

       sizeSpecialChar = i;
       printf("saut de %d char\n",i-fakeIndex);
       specialChar = malloc(sizeof(char)*(i-fakeIndex));

       for(i = fakeIndex; i < *index; i++){
         specialChar[i-fakeIndex] = c[i+fakeIndex];
         printf("%c ",specialChar[i-fakeIndex]);
       }

       *index = i; // saut d'index
       printf("stockage special char");
       stack_push(t, specialChar, sizeSpecialChar, *index);
       return 1;
     }
   }
   return 0;
 }

 void toNextChar(char* c, int* index, t_my_stack** t){
   printf("toNextChar\n");
   int i;
   i = *index;
   do{


     *index = ++i;
     //*(index++);

   }while(c[i] == ' ');
  *index = i-1;

   printf("next index: %d\n", *index);

 }

 void stack_push(t_my_stack** pointer_stack, char* value, unsigned int size, unsigned int index){
   t_my_stack* new_e = malloc(sizeof(t_my_stack));//création d'un nouvel élément;
   new_e->c = value;
   new_e->size =  size;
   new_e->index = index;
   new_e->pointer = *pointer_stack;

   *pointer_stack = new_e;//mise à jour de la valeur du pointeur sur stack

 }

t_my_stack stack_pop(t_my_stack** pointer_stack){
   //remove the next value from the stack and return it

      t_my_stack new_stack;
   t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
   if(my_stack == NULL){
     return new_stack;
   }else{

     new_stack.c = my_stack->c;
      new_stack.size = my_stack->size;

     *pointer_stack = my_stack->pointer;//modification de la valeur de pointeur stockée de le pointeur de pointeur (sur l'avt dernier element puisque le dernier element va être supprimé);
     //free(my_stack);

     return new_stack;
   }
 }

t_my_stack stack_peek(t_my_stack** pointer_stack){

   t_my_stack new_stack;
   t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
   if(my_stack == NULL){
     return new_stack;
   }else{

     new_stack.c = my_stack->c;
     new_stack.size = my_stack->size;
     return new_stack;
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
