//3d4-1 ����Ӷκ�����ļ��㷨  
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
	printf("����a����������Ӷκ�Ϊ��a[%d:%d]:%d\n", besti, bestj, MaxSum(6, a, &besti, &bestj));
	return 0;
}

int MaxSum(int n, int *a, int *besti, int *bestj)
{
	int sum = 0;
	for (int i = 0; i<n; i++)//���������ʼ��  
	{
		for (int j = i; j<n; j++)//������ͽ�����  
		{
			int thissum = 0;
			for (int k = i; k <= j; k++)//���  
			{
				thissum += a[k];
			}
			if (thissum>sum)//������Ӷκ�  
			{
				sum = thissum;
				*besti = i;
				*bestj = j;
			}
		}
	}
	return sum;
}