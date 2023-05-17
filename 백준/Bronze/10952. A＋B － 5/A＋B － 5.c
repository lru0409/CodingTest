#include <stdio.h>

int main(void)
{
	int num1, num2;

	while(1)
	{
		scanf("%d %d", &num1, &num2);
		if (num1 == 0)
			break;
		printf("%d\n", num1 + num2);
	}
	
	return (0);
}