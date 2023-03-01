#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element; 
typedef struct { 
     element stack[MAX_STACK_SIZE]; 
     int top; 
} StackType; 

void init(StackType *s) // 스택 초기화 함수 
{ 
     s->top = -1; 
} 

int is_empty(StackType *s) // 공백 상태 검출 함수 
{ 
     return (s->top == -1); 
} 

int is_full(StackType *s) // 포화 상태 검출 함수 
{ 
     return (s->top == (MAX_STACK_SIZE-1)); 
}

void push(StackType *s, element item) // 삽입함수 
{  
      if( is_full(s) ) { 
             fprintf(stderr,"스택 포화 에러\n"); 
             return;                
       } 
       else s->stack[++(s->top)] = item; 
} 

element pop(StackType *s) // 삭제함수
{  
    if( is_empty(s) ) { 
             fprintf(stderr, "스택 공백 에러\n"); 
             exit(1);               
     } 
     else return s->stack[(s->top)--]; 
}  

element peek(StackType *s) // 피크함수 
{ 
    if( is_empty(s) ) { 
             fprintf(stderr, "스택 공백 에러\n"); 
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
	printf("숫자 입력:");
	scanf_s("%s",postfix,sizeof(postfix));
    result = eval(postfix);
    printf("후위 표기식 %s의 계산 결과 : %d\n",postfix,result);
    return 0;
	system("pause");
}