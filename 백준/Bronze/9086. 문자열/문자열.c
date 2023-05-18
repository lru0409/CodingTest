#include <stdio.h>

int main(void)
{
    int count;
    char str[1000];
    int idx;

    scanf("%d", &count);

    for(int i = 0; i < count; i++)
    {
        scanf("%s", str);
        // 첫 글자 출력
        printf("%c", str[0]);
        // 마지막 글자 출력
        idx = 0;
        while (str[idx + 1])
            idx++;
        printf("%c\n", str[idx]);
    }

	return (0);
}