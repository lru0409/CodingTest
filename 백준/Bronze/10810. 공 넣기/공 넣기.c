int main(void)
{
	int n; // 바구니 개수
	int m; // 공을 넣는 횟수
	int i;

	scanf("%d %d", &n, &m);

	int baskets[n]; // 바구니의 공 번호를 저장하는 배열
	for(i = 0; i < n; i++)
		baskets[i] = 0;

	int start, end, ballNum; // start번부터 end번 바구니까지 ballNum 번호의 공을 넣음
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &start, &end, &ballNum);
		for(int j = start; j <= end; j++)
			baskets[j - 1] = ballNum;
	}

	for(i = 0; i < n; i++)
		printf("%d ", baskets[i]);

	return (0);
}