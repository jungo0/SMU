
#include <stdio.h>
#define ROW 5
#define COL 6
void Trans_array(int (*arr)[COL], int count);

void Trans_array(int (*arr)[COL], int count)
{
	int r,c;
	printf("\n전치행렬\n");
	printf("행\t열\t\n\n", COL, ROW, count);
	for (c = 0; c < COL; c++)
	{
		for (r = 0; r < ROW; r++)
			if(arr[r][c] !=0)
				printf("%d\t%d\t%d\n",r,c,arr[r][c]);
}
}
int main(void)
{
	int arr[ROW][COL] = {{0, 0, 4 ,3 ,0 },
	{ 0, 8, 0, 0, 1 },
	{ 7, 0, 0, 0, 5 }, 
	{ 0, 1, 0, 0, 0 },
	{ 0, 2, 8, 0, 0 }
	};
	int r,c ,count = 0;
	printf("희소행렬\n");
	printf("0  0  4  3  0\n0  8  0  0  1\n7  0  0  0  5\n0  1  0  0  0\n0  2  8  0  0");

		printf("\n");

Trans_array(arr,count);
}
