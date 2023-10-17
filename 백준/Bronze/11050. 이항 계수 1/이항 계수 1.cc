#include <iostream>
using namespace std;

int N, K;

void combination(int depth, int next, int *count)
{
	if (depth == K)
	{
		(*count) += 1;
		return ;
	}
	for(int i = next; i < N; i++)
	{
		combination(depth + 1, i + 1, count);
	}
}

int main()
{
	cin >> N >> K;

	int count = 0;
	combination(0, 0, &count);
	cout << count << endl;
	
	return 0;
}