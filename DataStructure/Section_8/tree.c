/*서치함수와 최대값을 못했고 결과도  안나옵니다*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100


typedef struct TreeNode
{
   char str[MAX_SIZE];
   int count;
   struct TreeNode *left, *right;
}TreeNode;

void inorder ( TreeNode *root)
{
   if(root)
   {
      inorder(root->left);
      printf("%s -> %d \n",root->str, root->count);
      inorder(root->right);
   }
   
}
/*
TreeNode  *search(TreeNode  *node, char str[MAX_SIZE])
{
      if ( node == NULL )  insert_node();
      if ( strcmp(str,node->str)==0 )   
   {
      node->count=node->count+1;
      return node;
   }
   */

void insert_node(TreeNode **root, char str[MAX_SIZE]) 
{
   TreeNode *p, *t;
   TreeNode *n;
   t = *root;
   p = NULL;
   while (t != NULL){
       if( strcmp(str, t->str)==0 )      
      {
         t->count+=1;
         return;
      }   
       p = t;
       if( strcmp(str,t->str)==-1 ) t = t->left;
       else t = t->right;
   }
   n = (TreeNode *) malloc(sizeof(TreeNode));
   n->count=1;
   strcpy(n->str, str);
   
   if( n == NULL ) 
	   return;
   strcpy(n->str, str);
   n->left = n->right = NULL;
   if( p != NULL ) 
      if( strcmp(str,p->str)==1)
         p->left = n;
      else p->right = n;
	  else *root = n;
}


int main()
{
   TreeNode *root=NULL;
   TreeNode *tmp;
   int i=0;
   char key[MAX_SIZE];
   for( i=0; i<10; i++)
   {
      printf("단어");
      scanf("%s", key);   
      insert_node(&root, key);
   }
   inorder(root); 
}
