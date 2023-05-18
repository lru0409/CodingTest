#include <stdio.h>

int main(void)
{
    int count;
    char str[100];

    scanf("%d\n%s", &count, str);

    int sum = 0;
    for(int i = 0; i < count; i++)
        sum += str[i] - '0';

    printf("%d\n", sum);

	return (0);
}