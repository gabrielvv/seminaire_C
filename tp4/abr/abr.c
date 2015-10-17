#include <stdio.h>
#include <stdlib.h>
#include "abr.h"

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
