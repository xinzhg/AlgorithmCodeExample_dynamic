//3d4-6 ���m�Ӷ�����  
#include <stdio.h>  

int MaxSum(int m, int n, int *a);

int main()
{
	int a[] = { 0, 2, 3, -7, 6, 4, -5 };//����ű��1��ʼ  
	for (int i = 1; i <= 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("����a����������Ӷκ�Ϊ:%d\n", MaxSum(3, 6, a));
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
	//ö���Ӷ���Ŀ����1��ʼ��������m�����Ƴ�b[i][j]��ֵ  
	for (int i = 1; i <= m; i++)
	{
		//n-m+i���Ʊ���������㣬��i=mʱ��j���Ϊn���ɾݴ˵�����������  
		for (int j = i; j <= n - m + i; j++)
		{
			if (j>i)
			{
				b[i][j] = b[i][j - 1] + a[j];//����a[j]ͬa[j-1]һ�𣬶������һ�Ӷ���  
				for (int k = i - 1; k<j; k++)
				{
					if (b[i][j]<b[i - 1][k] + a[j])
						b[i][j] = b[i - 1][k] + a[j];//�������һ�Ӷν�����a[j]  
				}
			}
			else
			{
				b[i][j] = b[i - 1][j - 1] + a[j];//��i=jʱ��ÿһ��Ϊһ�Ӷ�  
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