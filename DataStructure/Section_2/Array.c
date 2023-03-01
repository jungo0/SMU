/*6번까지 할수 있는대까지 최대한 했습니다 */
#include <stdio.h>
int factorial(int n);
int factorial2(int n);
int length(char arr[30]);
int length2(char *a, int n);
char contrast(char*ch, char*ch1);
char contrast2(char *s);

int factorial(int n)
{
	int last=1;
	int i;
	for(i=1; i<n; i++)
	{
		last*=i;                              
	}
		return ;
}

int factorial2(int n)
{
	if(n<=1) return 1;
	return  n* factorial2(n-1);
}

int length(char arr[30]) 
{
   int i = 0;
   int len = 0;

   for (i = 0; arr[i] != '\0'; i++) 
   {
      len++;
   }
   return len;
}

int length2(char *a, int n)
{
	if(a[n] != '\0')
	{
	n++;
	return length2(a,n);
	}
	if(a[n] == '\0')
		return n;
}

char contrast(char*ch, char*ch1)
{
	int i,j;
	for(j=0;j<100;j++)
	{
		if(ch[j] == '\0')
		{
			i=j;
		}
	}
}

char contrast2(char *s)
{
	if(*s==0)
		return;
	else
	{
		contrast2(s+1);
		printf("%c",*s);
	}
}

int main(void)
{
	int a;
	int n;
	int i;
	char ch[100];
	char arr[30];
	char ch1[100];
	char s[100];
	printf("factorial: ");
	scanf("%d",&n);
	printf("factorial: %d\n",factorial2(n));
	  printf("문자열 입력:");
      scanf_s("%s", arr,sizeof(arr));
      printf("문자열의 길이:%d\n", length(arr));
	printf("역순 문자열:");
	scanf("%s",s);
	contrast2(s);
	printf("\n");
	system("pause");
	return 0;
}