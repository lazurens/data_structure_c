#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int data;
        struct node *pright;
        struct node *pleft;
        }Node;
      
int main(int argc, char *argv[])
{
  Node *t = NULL;
  printf("call insert(t,5) : head\n");
  insert(&t,5);
  printf("call insert(t,4) : left\n");
  insert(&t,4);
  printf("call insert(t,6) : right\n");
  insert(&t,6);
  printf("PreOrder\n");
  print_preorder(t);
  printf("InOrder\n");
  print_inorder(t);
  printf("PostOrder\n");
  print_postorder(t);
  printf("About to DELETE the tree\n");
  deltree(t);
  printf("Tree was deleted node by node\n");
  int decision = search(*t,5);
  printf("decision = %d \n",decision);
  if(decision==1){
                   printf("Exists in the tree\n");
                   }else printf("Doesnt exists in the tree\n");
  system("PAUSE");	
  return 0;
}

int insert(Node **tree, int val){
    Node *temp = NULL;
    if(!(*tree)){
             temp = (Node *)malloc(sizeof(Node));
             temp->pleft = temp->pright = NULL;
             temp->data = val;
             *tree = temp;
             return 0;
             }
             
    if (val<(*tree)->data){
                   insert(&(*tree)->pleft,val);
                   }
    else 
    if (val > (*tree)->data){
                   insert(&(*tree)->pright,val);
                   }
    }


int print_preorder(Node *tree){
    if(tree){
         printf("%d\n",tree->data);
         print_preorder(tree->pleft);
         print_preorder(tree->pright);
         }
    }

int print_inorder(Node *tree){
    if(tree){
         print_preorder(tree->pleft);
         printf("%d\n",tree->data);
         print_preorder(tree->pright);
         }
    }

int print_postorder(Node *tree){
    if(tree){
         print_preorder(tree->pleft);
         print_preorder(tree->pright);
         printf("%d\n",tree->data);
         }
    }

int deltree(Node *tree){
    if(tree){
    deltree(tree->pleft);printf("%d call for left: \n",tree->pleft);
    deltree(tree->pright);printf("%d call for reght: \n",tree->pleft);
    free(tree);printf("%d this adress is free\n",tree);
         }
    }

int search(Node **tree, int val){
    int ok=0;
    if(!(*tree)){
         printf("\ncond1\n");ok=0;
         }
    if(val<(*tree)->data){
    printf("\ncond2\n");
         search(&((*tree)->pleft), val);
         }
    else 
    if(val>(*tree)->data){
    printf("\ncond3\n");
         search(&((*tree)->pright), val);
         }
    else 
    if(val==(*tree)->data){
         ok=1;
         }
         return ok;
    }
