#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100000];

bool binarySearch(int x)
{
	int start = 0;
	int end = N - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x == A[mid])
			return (true);
		else if (x < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (false);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	
	int M, X;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> X;
		if (binarySearch(X)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}