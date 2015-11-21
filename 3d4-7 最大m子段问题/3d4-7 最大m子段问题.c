//3d4-7 ���m�Ӷ�����  
#include <stdio.h>  
#include <stdlib.h>

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
	//int *b = new int[n + 1];
	//int *c = new int[n + 1];
	int *b = (int*)malloc((n + 1)*sizeof(int));
	int *c = (int*)malloc((n + 1)*sizeof(int));
	b[0] = 0;//b�����¼��i�е����i�Ӷκ�  
	c[1] = 0;//c�����¼��i-1�е����i-1�Ӷκ�  
	for (int i = 1; i <= m; i++)
	{
		b[i] = b[i - 1] + a[i];
		c[i - 1] = b[i];
		int max = b[i];
		//n-m+i���Ʊ���������㣬��i=mʱ��j���Ϊn���ɾݴ˵�����������  
		for (int j = i + 1; j <= i + n - m; j++)
		{
			b[j] = b[j - 1]>c[j - 1] ? b[j - 1] + a[j] : c[j - 1] + a[j];
			c[j - 1] = max;//Ԥ�ȱ����j-1�е����j-1�Ӷκ�  
			if (max<b[j])
			{
				max = b[j];
			}
		}
		c[i + n - m] = max;
	}
	int sum = 0;
	for (int j = m; j <= n; j++)
	{
		if (sum<b[j])
		{
			sum = b[j];
		}
	}
	return sum;
}