#include <stdio.h>

int main(void)
{
	int count;
	int num1, num2;

	scanf("%d", &count);

	for(int i = 1; i <= count; i++)
	{
		scanf("%d %d", &num1, &num2);
		printf("Case #%d: %d + %d = %d\n", i, num1, num2, num1 + num2);
	}

	return (0);
}