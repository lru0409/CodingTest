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
	for(int i = N - 1; i >= 0; i--)
	{
		result += K / coin[i];
		K = K % coin[i];
	}
	cout << result << endl;

	return (0);
}