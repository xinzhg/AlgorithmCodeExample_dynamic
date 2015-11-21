//3d3-2 最长公共子序列问题  
#include <stdio.h>  
const int M = 7;
const int N = 6;
void output(char *s, int n);
void LCSLength(int m, int n, char *x, char *y, int **c);
void LCS(int i, int j, char *x, int **c);
int main()
{
	//X={A,B,C,B,D,A,B}  
	//Y={B,D,C,A,B,A}  
	char x[] = { ' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B' };
	char y[] = { ' ', 'B', 'D', 'C', 'A', 'B', 'A' };
	/*int **c = new int *[M + 1];
	for (int i = 0; i <= M; i++)
	{
		c[i] = new int[N + 1];
	}*/
	int **c = (int**)malloc((M + 1)*sizeof(int*));
	for (int i = 0; i <= M; i++){
		c[i] = (int*)malloc((N + 1)*sizeof(int));
	}
	printf("序列X：\n");
	output(x, M);
	printf("序列Y：\n");
	output(y, N);
	LCSLength(M, N, x, y, c);
	printf("序列X、Y最长公共子序列长度为：%d\n", c[M][N]);
	printf("序列X、Y最长公共子序列为：\n");
	LCS(M, N, x, c);
	printf("\n");
}
void output(char *s, int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%c ", s[i]);
	}
	printf("\n");
}
void LCSLength(int m, int n, char *x, char *y, int **c)
{
	int i, j;
	for (i = 1; i <= m; i++)
		c[i][0] = 0;
	for (i = 1; i <= n; i++)
		c[0][i] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
}
void LCS(int i, int j, char *x, int **c)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (c[i][j] == c[i - 1][j - 1] + 1)
	{
		LCS(i - 1, j - 1, x, c);
		printf("%c ", x[i]);
	}
	else if (c[i - 1][j] >= c[i][j - 1])
	{
		LCS(i - 1, j, x, c);
	}
	else
	{
		LCS(i, j - 1, x, c);
	}
}