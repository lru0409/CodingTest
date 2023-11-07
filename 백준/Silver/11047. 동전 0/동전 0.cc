#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	int coin[10];
	for(int i = 0; i < N; i++)
		cin >> coin[i];
	
	int result = 0;
	int coin_idx = N - 1;
	while (K && 0 <= coin_idx)
	{
		if (coin[coin_idx] <= K)
		{
			int count = K / coin[coin_idx];
			result += count;
			K -= coin[coin_idx] * count;
		}
		coin_idx -= 1;
	}
	cout << result << endl;

	return (0);
}