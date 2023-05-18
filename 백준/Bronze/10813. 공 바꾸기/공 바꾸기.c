#include <stdio.h>

int main(void)
{
	int n; // 바구니 개수
	int m; // 공을 넣는 횟수

	scanf("%d %d", &n, &m);

	int baskets[n]; // 바구니의 공 번호를 저장하는 배열
	for(int i = 0; i < n; i++)
		baskets[i] = i + 1;

    int basket1, basket2, temp; // basket1과 basket2 바구니에 든 공 교환
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &basket1, &basket2);
        // swap
        temp = baskets[basket1 - 1];
        baskets[basket1 - 1] = baskets[basket2 - 1];
        baskets[basket2 - 1] = temp;
    }

	for(int i = 0; i < n; i++)
		printf("%d ", baskets[i]);

	return (0);
}