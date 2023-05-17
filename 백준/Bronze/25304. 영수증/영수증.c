#include <stdio.h>

int main(void)
{
	int totalPrice, typeCount;
	int objPrice, objCount;
	int sum = 0;

	scanf("%d\n%d", &totalPrice, &typeCount);

	for(int i = 0; i < typeCount; i++)
	{
		scanf("%d %d", &objPrice, &objCount);
		sum += objPrice * objCount;
	}

	if (totalPrice == sum)
		printf("Yes");
	else
		printf("No");

	return (0);
}