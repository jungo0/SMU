
#include <stdio.h>


void arradd(int arr[6][6])
{
		int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
		
			arr[5][j] += arr[i][j];
			arr[i][5] += arr[i][j];
			if(i==j)
		arr[5][5] += arr[i][j];
		}
	}
		
		

	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 6; j++)
		{
			printf("%6d", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{

	int arr[6][6] = {
		{1, 2, 3, 4, 5}, 
		{6, 7, 8, 9, 10}, 
		{11, 12, 13, 14, 15}, 
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	arradd(arr);
	system("pause");
	return 0;
}
