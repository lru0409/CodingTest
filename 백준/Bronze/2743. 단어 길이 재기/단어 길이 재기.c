#include <stdio.h>

int main(void)
{
    char str[100];

    scanf("%s", str);

    int idx = 0;
    while (str[idx])
        idx++;
    
    printf("%d", idx);
    
	return (0);
}