#include <stdio.h>

int main(void)
{
	int count;

	scanf("%d", &count);

	for(int i = 1; i <= count; i++)
	{
		for (int j = 0; j < count - i; j++)
			printf(" ");

		for(int k = 0; k < i; k++)
			printf("*");

		printf("\n");
	}

	return (0);
}