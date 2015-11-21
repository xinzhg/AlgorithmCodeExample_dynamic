//3d4-6 最大m子段问题  
#include <stdio.h>  

int MaxSum(int m, int n, int *a);

int main()
{
	int a[] = { 0, 2, 3, -7, 6, 4, -5 };//数组脚标从1开始  
	for (int i = 1; i <= 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("数组a的最大连续子段和为:%d\n", MaxSum(3, 6, a));
}

int MaxSum(int m, int n, int *a)
{
	if (n<m || m<1)
		return 0;
	//int **b = new int *[m + 1];
	int **b = (int**)malloc((m + 1)*sizeof(int*));
	for (int i = 0; i <= m; i++)
	{
		//b[i] = new int[n + 1];
		b[i] = (int*)malloc((n + 1)*sizeof(int));
	}
	for (int i = 0; i <= m; i++)
	{
		b[i][0] = 0;
	}
	for (int j = 1; j <= n; j++)
	{
		b[0][j] = 0;
	}
	//枚举子段数目，从1开始，迭代到m，递推出b[i][j]的值  
	for (int i = 1; i <= m; i++)
	{
		//n-m+i限制避免多余运算，当i=m时，j最大为n，可据此递推所有情形  
		for (int j = i; j <= n - m + i; j++)
		{
			if (j>i)
			{
				b[i][j] = b[i][j - 1] + a[j];//代表a[j]同a[j-1]一起，都在最后一子段中  
				for (int k = i - 1; k<j; k++)
				{
					if (b[i][j]<b[i - 1][k] + a[j])
						b[i][j] = b[i - 1][k] + a[j];//代表最后一子段仅包含a[j]  
				}
			}
			else
			{
				b[i][j] = b[i - 1][j - 1] + a[j];//当i=j时，每一项为一子段  
			}
		}
	}
	int sum = 0;
	for (int j = m; j <= n; j++)
	{
		if (sum<b[m][j])
		{
			sum = b[m][j];
		}
	}
	return sum;
}