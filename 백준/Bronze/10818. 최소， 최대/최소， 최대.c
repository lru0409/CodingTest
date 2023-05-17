#include <stdio.h>

int main(void)
{
	int n; // 정수 개수
	int num;
	int min, max; // 최솟값, 최댓값

	scanf("%d", &n);
	scanf("%d", &num);
	max = num;
	min = num;

	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d", &num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	printf("%d %d", min, max);

	return (0);
}