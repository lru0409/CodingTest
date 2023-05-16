#include <stdio.h>

int main(void)
{
    int num1, num2;
    int result1, result2, result3, totalResult;

    scanf("%d %d", &num1, &num2);

    result1 = num1 * (num2 % 10);
    result2 = num1 * ((num2 % 100) - (num2 % 10));
    result3 = num1 * ((num2 - (num2 % 100)));

    printf("%d\n%d\n%d\n", result1, result2/10, result3/100);
    printf("%d\n", result1 + result2 + result3);

    return (0);
}