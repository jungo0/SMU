 
#include <stdio.h>

typedef struct boksosu
 {
 int silsu;
 int sosu;

}boksosu;
boksosu add (boksosu);
boksosu sub (boksosu);
boksosu mul (boksosu);

boksosu add(boksosu a,boksosu b)
{
	boksosu i;
	i.silsu=a.silsu+b.silsu;
	i.sosu=a.sosu+b.sosu;
	return i;
}
boksosu sub(boksosu a,boksosu b)
{
	boksosu i;
	i.silsu=a.silsu-b.silsu;
	i.sosu=a.sosu-b.sosu;
	return i;
}
boksosu mul(boksosu a,boksosu b)
{
	boksosu i;
	i.silsu=(a.silsu*b.silsu)-(a.sosu*b.sosu);
	i.sosu=(b.sosu*a.silsu)+(b.silsu*a.sosu);
	return i;
}
int main(void)
{
	boksosu a,b;
	
	{
		printf("a+bi, c+di\n");
		scanf_s("%d %d",&a.silsu,&a.sosu);
		scanf_s("%d %d",&b.silsu,&b.sosu);
		printf("더하기 %d + %di\n",add(a,b).silsu,add(a,b).sosu);
		printf("빼기 %d + %di\n",sub(a,b).silsu,sub(a,b).sosu);
		printf("곱하기 %d + %di\n",mul(a,b).silsu,mul(a,b).sosu);
	}
	return 0;
}