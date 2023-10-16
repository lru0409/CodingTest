#include <iostream>
using namespace std;

int counting[20000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, card;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> card;
		counting[card + 10000000] += 1;
	}

	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> card;
		cout << counting[card + 10000000] << " ";
	}
	cout << endl;

	return 0;
}