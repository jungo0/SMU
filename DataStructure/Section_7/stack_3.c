/*3번 더하기는되고 최댓값은 오류나고 오름차순은 모르겠습니다*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int element;
typedef struct ListNode
{
 element data;
 struct ListNode *link; 
}ListNode;

void error(char *message)
{
 fprintf(stderr,"%s\n",message);
 exit(1);
}

ListNode * create_ListNode(element data,ListNode *link)
{
 ListNode *new_ListNode;
 new_ListNode = (ListNode *)malloc(sizeof(ListNode));
 if (new_ListNode == NULL) error ("메모리 할당 에러");
 new_ListNode->data =data;
 new_ListNode->link=link;
 return (new_ListNode);
}

void insert_ListNode(ListNode **phead,ListNode *p,ListNode *new_ListNode){
 if(*phead ==NULL) 
 { 
  new_ListNode->link=NULL;
 *phead =new_ListNode;
 }
 else if (p==NULL)
 {
  new_ListNode->link=*phead;
  *phead =new_ListNode;
 }
 else 
 {
  new_ListNode->link =p->link;
  p->link=new_ListNode;
 }
}

void display(ListNode *head){
 ListNode *p =head;
 while(p!=NULL)
 {
  printf("%d  ",p->data);
  p= p->link;
 }
 printf("\n");
}
ListNode * concat(ListNode *head1,ListNode *head2)
{




 ListNode *p;
 if(head1 == NULL )return head2;
 else if (head2 == NULL) return head1;
 else {
  p=head2;
  while(p->link !=NULL){
   p=p->link;
  }
   p->link =head1;
   return head2;
 }
}

void Listsum( ListNode *head )
{
	ListNode *p=head;
	int sum=0;
	while( p != NULL )
	{
		sum += p->data;
		p = p->link;
    }
		printf("합: %d",sum);

 }
/*
int ListDataMax (ListNode *s ,int r)
{
	ListNode *p=head;
	int i;
	ListNode*max;
	max = (ListNode *)malloc(sizeof(ListNode));
	s = head->p;
	max->data = s->data;
	s =s->p;
	for(i=0;i<r;i++)
	{
		if(s->data > max->data)
		{
			max->data --= s->data;
			s = s->p;
		}
		else
			s = s->p;
	}
	s = head->p;
	for(i=0;i<r;i++)
	{
		if(max->data == s->data)
		{
			max=s;
			break;
		}
		else
			s = s->p;
	}
	return max;
}
*/
void main()
{
	ListNode *list1=NULL;
	insert_ListNode(&list1,NULL,create_ListNode(10,NULL));
	insert_ListNode(&list1,NULL,create_ListNode(20,NULL));
	insert_ListNode(&list1,NULL,create_ListNode(30,NULL));
	insert_ListNode(&list1,NULL,create_ListNode(40,NULL));
	display (list1);
	Listsum(list1);
	system("pause");
}

