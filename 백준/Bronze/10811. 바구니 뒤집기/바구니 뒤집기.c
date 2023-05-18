#include <stdio.h>

int baskets[100]; // 바구니 순서를 저장하는 배열

void sort_reverse(int startIdx, int endIdx)
{
    int temp;

    for(int i = 0; i <= (endIdx - startIdx)/2; i++)
    {
        temp = baskets[startIdx + i];
        baskets[startIdx + i] = baskets[endIdx - i];
        baskets[endIdx - i] = temp;
    }
}

int main(void)
{
    int n, m; // 바구니 개수, 뒤집는 횟수

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        baskets[i] = i + 1;

    int start, end; // start 부터 end 까지의 바구니 순서를 뒤집기
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &start, &end);
        sort_reverse(start - 1, end - 1);
    }

    for(int i = 0; i < n; i++)
        printf("%d\n", baskets[i]);

	return (0);
}