#include <stdio.h>

int main(void)
{
    int y;
    int ret = 0;

    scanf("%d", &y);

    if (y % 4 == 0 && y % 100 != 0)
        ret = 1;
    if (y % 400 == 0)
        ret = 1;
    
    printf("%d", ret);

    return (0);
}