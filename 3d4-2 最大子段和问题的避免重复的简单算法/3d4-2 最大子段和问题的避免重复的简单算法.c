//3d4-2 最大子段和问题的避免重复的简单算法  
#include <stdio.h>  

int MaxSum(int n, int *a, int *besti, int *bestj);

int main()
{
	int a[] = { -2, 11, -4, 13, -5, -2 };
	for (int i = 0; i<6; i++)
	{
		printf("%d ", a[i]);
	}
	int besti, bestj;
	printf("\n");
	printf("数组a的最大连续子段和为：a[%d:%d]:%d\n", besti, bestj, MaxSum(6, a, &besti, &bestj));
	return 0;
}

int MaxSum(int n, int *a, int *besti, int *bestj)
{
	int sum = 0;
	for (int i = 0; i<n; i++)//控制求和起始项  
	{
		int thissum = 0;
		for (int j = i; j <= n; j++)//控制求和结束项  
		{
			thissum += a[j];//求和  
			if (thissum>sum)
			{
				sum = thissum;
				*besti = i;
				*bestj = j;
			}
		}
	}
	return sum;
}