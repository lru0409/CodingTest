#include <stdio.h>

int main(void)
{
	int n; // 정수 개수
	int x; // 비교 기준 값
	int num; // 수열의 숫자

	scanf("%d %d", &n, &x);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num < x)
			printf("%d ", num);
	}

	return (0);
}