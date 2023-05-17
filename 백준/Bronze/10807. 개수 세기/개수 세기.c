#include <stdio.h>

int main(void)
{
	int count, findNum;
	int result = 0;

	scanf("%d", &count);

	int numbers[count];
	for(int i = 0; i < count; i++)
		scanf("%d", &numbers[i]);

	scanf("%d", &findNum);

	for(int i = 0; i < count; i++)
	{
		if (numbers[i] == findNum)
			result++;
	}
	printf("%d", result);

	return (0);
}