#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int D, K;
	cin >> D >> K;

	int A[31] = { 0, 1, 0, };
	int B[31] = { 0, 0, 1, };
	for(int i = 3; i <= 30; i++)
	{
		A[i] = A[i-1] + A[i-2];
		B[i] = B[i-1] + B[i-2];
	}

	for(int i = 1; i <= K; i++)
	{
		int b = K - (A[D] * i);
		if (b % B[D] == 0)
		{
			cout << i << endl << b / B[D] << endl;
			return (0);
		}
	}
	
	return (0);
}