#include <stdio.h>
#include <stdlib.h>
#include "abr.h"


typedef struct s_node {
 	    int value;
 		struct s_node * left;
 		struct s_node * right;
 	} t_node;

 	void abr_insert(t_node** root, int value);
    // Display from the example : 1 2 3 4 5 6 7 9 10
    void abr_display_asc(t_node* root);



void abr_insert(t_node** root, int value)
{
    t_node *tmpNode;
    t_node *tmpTree = *root;

    t_node *elem = malloc(sizeof(t_node));
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(value > tmpTree->value )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    else  *root = elem;
}

void abr_display_asc(t_node* root)
{
    if(!root) return;

    if(root->left)  abr_display_asc(root->left);

    printf("%d ", root->value);

    if(root->right) abr_display_asc(root->right);
}


/*int main(int argc, char** argv){

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
}*/
