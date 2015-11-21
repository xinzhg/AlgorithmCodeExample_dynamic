//3m2 避免重复运算的斐波那契数列运算  
#include <stdio.h>  
#include <map>   
void input(int *n);
int fib(int n, map<int, int>);
int main()
{
	map<int, int>   my_Map;
	int n;
	input(&n);
	printf("fib(%d)=%d\n", n, fib(n, my_Map));
	return 0;
}
void input(int *n)
{
	printf("请输入n:\n");
	scanf("%d", n);
}
int fib(int n, map<int, int> my_Map)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		map<int, int>::iterator iter = my_Map.find(n);
		if (iter == my_Map.end())
		{
			int temp = fib(n - 1, my_Map) + fib(n - 2, my_Map);
			my_Map.insert(pair<int, int>(n, temp));
			return temp;
		}
		else
		{
			return iter->second;
		}
	}
}