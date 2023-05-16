#include <stdio.h>

int main(void)
{
    int a, b, c;
    int max;

    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c)
    {
        printf("%d", 10000 + (a * 1000));
    }
    else if (a == b || a == c)
    {
        printf("%d", 1000 + (a * 100));
    } 
    else if (b == c)
    {
        printf("%d", 1000 + (b * 100));
    }
    else
    {
        if (a > b && a > c)
            max = a;
        else if (b > a && b > c)
            max = b;
        else
            max = c;
        printf("%d", 100 * max);
    }

    return (0);
}