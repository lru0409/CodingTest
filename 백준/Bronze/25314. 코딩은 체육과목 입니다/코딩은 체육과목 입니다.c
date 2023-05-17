#include <stdio.h>

int main(void)
{
	int nByte;

	scanf("%d", &nByte);

	for(int i = 0; i < nByte/4; i++)
	{
		printf("long ");
	}
	printf("int");

	return (0);
}