#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
int top = -1;
int	front = 0;

typedef struct {

	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);

void init(StackType *s) // ���� �ʱ�ȭ �Լ� 

{
	s->top = -1;
}

int is_empty(StackType *s) // ���� ���� ���� �Լ� 

{
	return (s->top == -1);
}

int is_full(StackType *s) // ��ȭ ���� ���� �Լ� 

{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) // �����Լ� 

{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}


element pop(StackType *s) // �����Լ�

{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType *s) // ��ũ�Լ� 
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}


void main() {

   StackType stack;
   char str[20];
   int a,i = 0;
   char ch[20],arr[20],b;
   int count = 0;

   init(&stack);
   printf("���ڿ� �Է�:\n");
   scanf_s("%s", str);
   
   for (i = 0; str[i] != '\0'; i++)

   {
      b = str[i];
      if (b != ' ') 
	  {
         push(&stack, b);
      }
      count++;

   }
    for(i=0;str[i]; i++)
    {
        if((str[i]>='a')&&(str[i]<='z'))
        {
            str[i] = str[i]-'a'+'A';
        }
        else
        {
            if((str[i]>='A')&&(str[i]<='Z'))
            {
                str[i] = str[i]-'A'+'a';
            }
        }
    }
 
   for (i = 0; i < count; i++)
   {
      arr[i] = pop(&stack);
   }
   count = 0;
   for (i = 0; str[i] != '\0'; i++)
   {
      b = str[i];
      if (b != ' ')
	  {
         push(&stack, b);
      }
      count++;
   }

   a = 0;
   for (i = 0; str[i] != '\0'; i++) 
   {
      ch[i] = pop(&stack);
      if (str[i]==ch[i]||str[i]-32==ch[i]||str[i]+32==ch[i]) 
	  {
         a++;
      }
   }

   if (a == count)
   {
      printf("ȸ���Դϴ�\n");
   }
   else 
   {
      printf("ȸ���̾ƴմϴ�\n");
   }

   front = 0;
   top = -1;
   system("pause");
}

 