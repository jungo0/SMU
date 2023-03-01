#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element; 
typedef struct { 
     element stack[MAX_STACK_SIZE]; 
     int top; 
} StackType; 

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
     return (s->top == (MAX_STACK_SIZE-1)); 
}

void push(StackType *s, element item) // �����Լ� 
{  
      if( is_full(s) ) { 
             fprintf(stderr,"���� ��ȭ ����\n"); 
             return;                
       } 
       else s->stack[++(s->top)] = item; 
} 

element pop(StackType *s) // �����Լ�
{  
    if( is_empty(s) ) { 
             fprintf(stderr, "���� ���� ����\n"); 
             exit(1);               
     } 
     else return s->stack[(s->top)--]; 
}  

element peek(StackType *s) // ��ũ�Լ� 
{ 
    if( is_empty(s) ) { 
             fprintf(stderr, "���� ���� ����\n"); 
             exit(1);               
     } 
     else return s->stack[s->top]; 
} 

int eval(char exp[]){
    int op1, op2, value, i;
    int len = (int) strlen(exp);
    char ch;
    StackType s;
    init(&s);
    for (i=0; i<len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
            continue;
        }
        
        op1 = pop(&s);
        op2 = pop(&s);
        
        switch (ch) {
            case '+': value = op1 + op2; break;
            case '-': value = op1 - op2; break;
            case '*': value = op1 * op2; break;
            case '/': value = op1 / op2; break;
            default: exit(1); break;
        }
        push(&s, value);
    }
    return pop(&s);
}


int main(){
    int result;
	char postfix[50];
	printf("���� �Է�:");
	scanf_s("%s",postfix,sizeof(postfix));
    result = eval(postfix);
    printf("���� ǥ��� %s�� ��� ��� : %d\n",postfix,result);
    return 0;
	system("pause");
}