#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int numbers[100001];
	int sums[100001] = {0};
	for(int i = 1; i <= N; i++)
	{
		cin >> numbers[i];
		sums[i] = sums[i - 1] + numbers[i];
	}
	
	int i, j;
	for(int k = 0; k < M; k++)
	{
		cin >> i >> j;
		cout << sums[j] - sums[i - 1] << '\n';
	}

	return (0);
}