#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleHeight(vector<int> trees, int height, int M)
{
	long long sum = 0;
	for(size_t i = 0; i < trees.size(); i++)
		if (trees[i] > height) sum += trees[i] - height;
	if (sum >= M) return (true);
	return (false);
}

int binarySearch(vector<int> trees, int M, int max)
{
	int start = 0, end = max - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (isPossibleHeight(trees, mid, M))
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (end);
}

int main()
{
	int N, M, max = 0;;
	cin >> N >> M;

	vector<int> trees(N);
	for(int i = 0; i < N; i++)
	{
		cin >> trees[i];
		if (trees[i] > max) max = trees[i];
	}

	cout << binarySearch(trees, M, max) << endl;

	return (0);
}