#include <stdio.h>

int main(void)
{
    char s[1000]; // 단어 s에서
    int i; // i번째 글자 출력

    scanf("%s\n%d", s, &i);
    printf("%c", s[i - 1]);

	return (0);
}