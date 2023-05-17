#include <stdio.h>

int main(void)
{
	int num1, num2;

	while(1)
	{
		if (scanf("%d %d", &num1, &num2) == EOF)
			break;
		printf("%d\n", num1 + num2);
	}

	return (0);
}