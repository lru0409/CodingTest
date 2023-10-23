#include <iostream>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	bool is_not_prime[1000001] = { false, }; // false면 소수
	is_not_prime[1] = true;

	for(int i = 2; i * i <= N; i++)
	{
		if (is_not_prime[i]) continue;
		for(int j = i * i; j <= N; j += i)
			is_not_prime[j] = true;
	}

	for(int i = M; i <= N; i++)
	{
		if (!is_not_prime[i])
			cout << i << '\n';
	}

	return (0);
}