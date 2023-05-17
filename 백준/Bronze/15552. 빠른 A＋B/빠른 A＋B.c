#include <stdio.h>

int main(void)
{
	int count;
	int num1, num2;

	scanf("%d", &count);

	for(int i = 0; i < count; i++)
	{
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1 + num2);
	}

	return (0);
}