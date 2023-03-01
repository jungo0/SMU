
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
struct {

 int coef;
 int expon;

}terms[MAX_TERMS]={ {8,3}, {7,1}, {1,0}, {10,3}, {3,2},{1,0} };
int avail =6;

char compare(int a, int b)
{	if( a>b ) return '>';
	else if( a==b ) return '=';
	else return '<';
}

void attach(float coef, int expon)
{	if( avail>MAX_TERMS ){
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef=coef;
	terms[avail++].expon=expon;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) 
{	
	int i;
	float tempcoef;
	*Cs = avail;
	while( As <= Ae && Bs <= Be )
	 switch(compare(terms[As].expon,terms[Bs].expon)){ 
	 case '>': 
		attach(terms[As].coef, terms[As].expon);
		As++; break;
	 case '=': 	
		tempcoef = terms[As].coef - terms[Bs].coef;
		if( tempcoef ) 
		 attach(tempcoef,terms[As].expon);
		As++; Bs++; break;
	 case '<': 
		attach(terms[Bs].coef, terms[Bs].expon);
		Bs++; break;
	}
	for(;As<=Ae;As++)
		attach(terms[As].coef, terms[As].expon);

	for(;Bs<=Be;Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail -1;
	printf("다항식1: ");
	for (i = 0; i < 3; i++) {
  if (i != 3) {
   printf("+");
  }
  printf("%dx^%d ", terms[i].coef, terms[i].expon);
 }
	  printf(" -  다항식2: ");
	for (i = 3; i < 6; i++) {
  if (i != 3) {
   printf("+");
  }
  printf("%dx^%d ", terms[i].coef, terms[i].expon);
 }
	  printf("\n");

	for (i = 6; i < 9; i++) {
  if (i != 3) {
   printf("+");
  }

  printf(" %dx^%d ", terms[i].coef, terms[i].expon);
 }
}
void main()
{
	int Cs,Ce;
	int i;
	
	poly_add2(0,2,3,5,&Cs,&Ce);
	system("pause");
}
