//3m1 未优化斐波那契数列计算  
#include <stdio.h>  

void input(int *n);
int fib(int n);
int main()
{
	int n;
	input(&n);
	printf("fib(%d)=%d\n", n, fib(n));
	return 0;
}
void input(int *n)
{
	printf("请输入n:\n");
	scanf("%d", n);
}
int fib(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}