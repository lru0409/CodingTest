#include <stdio.h>

int main(void)
{
    int h, m, t;

    scanf("%d %d\n%d", &h, &m, &t);

    m += t;

    if (m/60 >= 1)
    {
        h += m/60;
        m = m%60;

        if (h > 23)
        {
            h -= 24;
        }
    }
    printf("%d %d", h, m);

    return (0);
}