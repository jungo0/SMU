/*컴파일러 비주얼*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 101
typedef struct 
{
	int degree;
	int coef[MAX];
}poly;

void print_poly(poly A)
{
	int i;
	for(i=0; i<A.degree; i++)
	{
		if(A.coef[i] !=0)
		printf("%dx^%d", A.coef[i], A.degree -i);
		if(A.coef[i + 1]>= 0&& A.coef[i] !=0)
			printf(" + ");

	}
	printf("%d",A.coef[A.degree]);

}

poly poly_save()
{
	poly A;
	int i;
	int num1, num2;
	printf("(1)");
	printf("최고차항 \n");
	scanf_s("%d",&num1);
	A.degree = num1;

	for(i =0; i<= num1; i++)
	{
		printf("x^%d의 계수\n", num1 -i);
		scanf_s("%d", &num2);
		A.coef[i] = num2;
	}
	return A;

}

int eval(poly A, int x)
{
	int sum =0;
	int i;
	int max;
	int a,b;
	printf("\n(3)최고차항 \n");
	scanf_s("%d", &max);
	A.degree = max;
	for(i=0; i<max+1; i++)
	{
		scanf("%d", &(A.coef[i]));
	}
	for(i=0; i<max+1; i++)
	{
		printf("%d차항계수 : %d\n", max-i,A.coef[i]);

	}
	  printf(" 다항식:");
   for (i = 0; i < max + 1; i++) 
   {
      if (i != 0 && A.coef[i] != 0)
         printf("+");
      if (A.coef[i] == 0) 
	  {
	  }


	   else 
	   {
         printf("%dx^%d", A.coef[i], A.degree - i);
	  }
   }
    printf("\nx :");
   scanf_s("%d", &x);
   for (i = 0; i < A.degree + 1; i++) 
   {
      a = (int)pow(x, A.degree - i);
      b = a * A.coef[i];
      sum = sum + b;
   }
   printf("\n x값 대입:%d\n\n", sum);
   return;
}

int main()
{
	int x;
	poly A;
	A = poly_save();
	print_poly(A);
	eval(A, 0);
	system("pause");
	return 0;
}