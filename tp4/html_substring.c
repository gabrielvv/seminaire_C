#include <stdio.h>
#include <stdlib.h>
#include "html_substring.h"

typedef struct s_my_stack {
  char* c;
  unsigned int size;
  unsigned int index;
  struct s_my_stack* pointer;
} t_my_stack;


void stack_push(t_my_stack** pointer_stack, char* value, unsigned int size, unsigned int index);
t_my_stack* stack_peek(t_my_stack** pointer_stack);
t_my_stack* stack_pop(t_my_stack** stack);
void free_stack(t_my_stack* stack);
int strlength(char *t);
void toNextChar(char* c, int* index, t_my_stack** stack);
short isSpecialChar(char* c, int* index, t_my_stack** stack);
void detectBaliseAndStack(char* input, int* index, t_my_stack** lifo, t_my_stack** fifo);
//char* html_substring(char* input, int length, char* appender);


/*int main(int argc, char** argv){
  //printf("String passee a la fonction: %s\n", argv[1]);
  //system("pause");
  printf("resultat: %s",html_substring(argv[1], 15, NULL));
  return 0;
}*/
 /*
 ** char* input the html to process.
 ** int the length of the substring.
 ** char* appender, optionnal, (if not null), append this suffix to the resulting chain.
 ** /!\ if an appender is present, his length his substract from global length.
 */

char* html_substring(char* input, int length, char* appender){

  //const short int DEHORS = 0;
  //const short int DEDANS = 1;

   t_my_stack* lifo = NULL;
   t_my_stack* fifo = NULL;
   //t_my_stack* stack2 = NULL;
   int* index;
   index = malloc(sizeof(int));
   *index = 0;
   int compteur = 0, j = 0;
   char* output = NULL;

   //printf("longueur de l'entree: %d", strlength(input));

   for(*index = 0; *index < strlength(input); *index = *index+1 ){
     if(compteur == length){//probleme si il y a le nombre exact de caractères
        //printf("compteur == length\n");

        if(appender != NULL){
          int size = strlength(appender);
           stack_push(&lifo, appender, size+1, *index);
        }
        break;
     }
     //printf("iteration index=%d caractere: %c\n", *index, input[*index]);
     //printf("compteur: %d\n", compteur);
     if(input[*index] == '<'){
       detectBaliseAndStack(input,index,&lifo,&fifo);//fait sauter l'index
       continue;
     }
     else if(input[*index] == '&'){
       //printf("specialChar\n");
        if(isSpecialChar(input, index, &fifo)){
          compteur++;
          //printf("compteur %d et index %d\n", compteur, *index);
          continue;
        }else{
          //printf("autre\n");
          compteur++;
          char* c = malloc(sizeof(char));
          *c = input[*index];
          stack_push(&lifo, c, 1, *index);
          //fait sauter l'index si rencontre un specialChar
         //stocke specialChar si existe sinon stocke caractère courant
        }
     }else if(input[*index] == ' '){
       //printf("espace\n");
       short int i;
       i = *index;
       do{
         *index = ++i;
         //*(index++);
       }while(input[i] == ' ');
      *index = i-1;// variable i locale
      char* c = malloc(sizeof(char));
      *c = ' ';
       //printf("stockage espace et saut a index: %d\n", *index);
      stack_push(&fifo , c, 1, *index);
      compteur++;
       //stocke un espace et fait sauter l'index au prochain caractère
     }
     else if(input[*index] != '\0'){
       //printf("stockage caract\213re: %c\n", input[*index]);
       compteur++;
       char* c = malloc(sizeof(char));
       *c = input[*index];
       stack_push(&fifo, c, 1, *index);
     }else{
       //printf("else = > break\n");
       break;
     }
     //*index = *index+1;
   }

   //printf("sortie de boucle\n");
   int size = 0;
   //output = malloc(sizeof(char)*size);
   t_my_stack* stack;

   t_my_stack* new_fifo = fifo;
    while((stack = stack_pop(&fifo)) != NULL){
     char* c = stack->c;
      stack_push(&lifo , c, stack->size, *index);
    }

    /***calcul de la taille totale du rendu final***/
    //printf("recuperation de la taille");
    stack = stack_peek(&lifo);
    do{
      size += stack->size;
    }while((stack = stack->pointer) != NULL);

    /***Allocation dynamique et remplissage de la chaine de caractère par dépilement d'une pile LIFO***/
    output = malloc(sizeof(char)*size);
    //printf("allocation memoire de taille %d a l'adresse %p\n",size, output);
    *index = 0;
    t_my_stack* new_lifo = lifo;
    while((stack = stack_pop(&lifo)) != NULL){
      char* c = stack->c;
      //printf("taille chaine restitue %s\n", stack->c);
      //int count;
      for(j = 0; j < stack->size; j++){
        if(c[j] != '\0'){
          //count = j;
          output[*index+j] = c[j];
          //printf("depile : index %d => %c\tindex %d => %c\n", *index+j, output[*index+j], j, c[j]);
        }
        else{
          //printf("a rencontré caractère de fin de chaine\n");
          //j = stack->size;
          break;
        }


      }
      *index = *index+j;
   }
   //printf("index du caractère de fin %d\n", *index);
   output[*index] = '\0';
   free_stack(new_fifo);
   free_stack(new_lifo);
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
     return taille;
 }

 void detectBaliseAndStack(char* input, int* index, t_my_stack** lifo, t_my_stack** fifo){
   int i = 0;
   //printf("detectBaliseAndStack recoit index %d\n", i);
   int j = 0;
   int attr = 0;
   int indexFermetureBalise, sizeBaliseO, sizeBaliseF;
   while(input[*index+i] != '>' && input[*index+i] != '\0'){
     i++;
     if(input[*index+i] == ' ' && !attr){
        attr = 1;
        indexFermetureBalise = i+1;
      }
   }


   if(input[*index+i] != '\0'){
   //printf("> detecte a %d\n", i+1);
   sizeBaliseO = i+2;

   if(!attr){
  //  printf("sizeBaliseF = sizeBaliseO+2");
     sizeBaliseF = sizeBaliseO;
   }
   else{

     sizeBaliseF = indexFermetureBalise+1;
      //printf("sizeBaliseF = %d", sizeBaliseF);
   }

   char* baliseF = malloc(sizeof(char)*sizeBaliseF);
   char* baliseO = malloc(sizeof(char)*(sizeBaliseO));
  // printf("allocation memoire a l'adresse %p\n", baliseO);
   for(i = *index; i < (sizeBaliseO+*index); i++){
     if((i-*index) == 1){
       //printf("ajout / ds balise\n");
       baliseF[i-(*index)] = '/';
       j++;
     }else if((i-*index) > 1){
       baliseO[i-*index-j] = input[i-j];
       if(i < sizeBaliseF+*index){
          baliseF[i-*index] = input[i-j];
        }
       //printf("index: %d => %c\t index: %d => %c\n", i-(*index)-j,baliseO[i-(*index)-j],i-j, input[i-j]);
     }else{
       //printf("copie du premier caractere\n");
       baliseF[i-*index] = input[i];
       baliseO[i-*index-j] = input[i];
        //printf("index: %d => %c\t index: %d => %c\n", i-(*index),baliseO[i-(*index)],i, input[i]);
     }
   }
   attr ? baliseF[sizeBaliseF-1] = '>' : 0;
   baliseF[sizeBaliseF] = '\0';
   baliseO[sizeBaliseO] = '\0';
   //printf("\n");
   //printf("stockage %s a l'index %d avec une taille de %d\n", baliseF, *index, sizeBalise);
   stack_push(lifo , baliseF, sizeBaliseF, *index);
   stack_push(fifo , baliseO, sizeBaliseO-1, *index);
   //system("pause");
   //printf("saut d'index a %d\n", i-1 );
   *index = i-2;//puisque index va s'incrémenter juste après l'exécution de cette fction en fin de boucle on retire -1
  }
 }


 short isSpecialChar(char* c, int* index, t_my_stack** t){

   char* specialChar;
   int i, sizeSpecialChar;
   //printf("specialChar recupere: %s\n", c);

   for(i = *index; i < *index+9; i++){
     if(c[i] == ' '){
       return 0;
     }
     else if(c[i] == ';'){

       sizeSpecialChar = i-*index+2;

       specialChar = malloc(sizeof(char)*(sizeSpecialChar));

       for(i = *index; i < (*index + sizeSpecialChar); i++){
         specialChar[i-*index] = c[i];
         //printf("%c ",specialChar[i-*index]);
       }
      //  printf("saut de %d char à l'index %d\n",sizeSpecialChar, i);
       *index = i-2; // saut d'index
       specialChar[sizeSpecialChar-1] = '\0';
       //printf("stockage special char %s de taille %d\n", specialChar, sizeSpecialChar);
       stack_push(t, specialChar, sizeSpecialChar, *index);
       return 1;
     }
   }
   return 0;
 }


 void stack_push(t_my_stack** pointer_stack, char* value, unsigned int size, unsigned int index){
   //printf("stack push\n");
   t_my_stack* new_e = malloc(sizeof(t_my_stack));//création d'un nouvel élément;
   //printf("stack push creation allocation memoire %p\n", new_e);
   new_e->c = value;
   new_e->size =  size;
   new_e->index = index;
   new_e->pointer = *pointer_stack;
   //printf("stack push creation %p\n", new_e);
   *pointer_stack = new_e;//mise à jour de la valeur du pointeur sur stack

 }

t_my_stack* stack_pop(t_my_stack** pointer_stack){
   //remove the next value from the stack and return it


   t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
   if(my_stack == NULL){
     return NULL;
   }else{

     *pointer_stack = my_stack->pointer;//modification de la valeur de pointeur stockée de le pointeur de pointeur (sur l'avt dernier element puisque le dernier element va être supprimé);
      //printf("stack pop destruction %p\n", my_stack);
     //free(my_stack);

     return my_stack;
   }
 }

t_my_stack* stack_peek(t_my_stack** pointer_stack){

   t_my_stack* my_stack = *pointer_stack;//initialisation de pointeur sur la valeur de pointeur contenue ds le pointeur de pointeur
   if(my_stack == NULL){
     return NULL;
   }else{

     return my_stack;
   }
 }

 void free_stack(t_my_stack* stack){
   //printf("free stack");
   t_my_stack** pointer_stack = &stack;
   //printf("boucle");
   while((stack = stack->pointer) != NULL){
     //printf("free %p", stack);
     free(*pointer_stack);
     *pointer_stack = stack;
   }

   free(*pointer_stack);

 }
