//3d4-5 ����Ӿ���֮������  
#include <stdio.h>  
//const int M = 4;
//const int N = 3;
#define M 4
#define N 3

int MaxSum(int n, int *a);
int MaxSum2(int m, int n, int a[M][N]);
int main()
{
	int a[M][N] = { { 4, -2, 9 }, { -1, 3, 8 }, { -6, 7, 6 }, { 0, 9, -5 } };
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("����a����������Ӷκ�Ϊ:%d\n", MaxSum2(M, N, a));
	return 0;
}
int MaxSum2(int m, int n, int a[M][N])
{
	int sum = 0;
	//int *b = new int[n + 1];
	int *b = malloc((n + 1)*sizeof(int));
	for (int i = 0; i<m; i++)//ö����  
	{
		for (int k = 0; k<n; k++)
		{
			b[k] = 0;
		}
		for (int j = i; j<m; j++)//ö�ٳ�ʼ��i,������j  
		{
			for (int k = 0; k<n; k++)
			{
				b[k] += a[j][k];//b[k]Ϊ������֮��  
				int max = MaxSum(n, b);
				if (max>sum)
				{
					sum = max;
				}
			}
		}
	}
	return sum;
}
int MaxSum(int n, int *a)
{
	int sum = 0, b = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b>0)
		{
			b += a[i];
		}
		else
		{
			b = a[i];
		}
		if (b>sum)
		{
			sum = b;
		}
	}
	return sum;
}