//3d1-1 �ص�������ĵݹ����Ž�  
//A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25  
//p[0-6]={30,35,15,5,10,20,25}  
#include <stdio.h>  
const int L = 7;
int RecurMatrixChain(int i, int j, int **s, int *p);//�ݹ������Ž�  
void Traceback(int i, int j, int **s);//�������Ž�  

int main()
{
	int p[] = { 30, 35, 15, 5, 10, 20, 25 };
	int **s = (int**)malloc(L*sizeof(int*));
	for (int i = 0; i < L; i++){
		s[i] = (int*)malloc(L*sizeof(int));
	}
	printf("��������ټ������Ϊ��%d\n", RecurMatrixChain(1, 6, s, p));
	printf("�������ż������Ϊ��\n");
	Traceback(1, 6, s);
	return 0;
}

int RecurMatrixChain(int i, int j, int **s, int *p)
{
	if (i == j) return 0;
	int u = RecurMatrixChain(i, i, s, p) + RecurMatrixChain(i + 1, j, s, p) + p[i - 1] * p[i] * p[j];
	s[i][j] = i;
	for (int k = i + 1; k<j; k++)
	{
		int t = RecurMatrixChain(i, k, s, p) + RecurMatrixChain(k + 1, j, s, p) + p[i - 1] * p[k] * p[j];
		if (t<u)
		{
			u = t;
			s[i][j] = k;
		}
	}
	return u;
}
void Traceback(int i, int j, int **s)
{
	if (i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	printf("Multiply A%d,%d", i, s[i][j]);
	printf(" and A%d,%d\n", (s[i][j] + 1), j);
}