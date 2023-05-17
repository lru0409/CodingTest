#include <stdio.h>

int main(void)
{
	int n;
	int total = 0;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		total += i;
	}
	printf("%d", total);

	return (0);
}