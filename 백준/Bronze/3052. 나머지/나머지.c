#include <stdio.h>

int main(void)
{
    int remainders[10]; // 나머지를 저장하는 배열
    int input, isDuplicated;
    int count = 0;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &input);
        remainders[i] = input % 42;

        isDuplicated = 0; // false
        for(int j = 0; j < i; j++)
        {
            if (remainders[j] == remainders[i])
                isDuplicated = 1; // true
        }
        if (isDuplicated == 0) // 이전 값과 중복되지 않았다면
            count++;
    }
    printf("%d\n", count);

	return (0);
}