#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> unHeard;
vector<string> result;

bool binarySearch(int start, int end, string target)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (target == unHeard[mid])
			return (true);
		else if (target < unHeard[mid])
			end = mid - 1;
		else // target > unHeard[mid]
			start = mid + 1;
	}
	return (false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	string input;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		unHeard.push_back(input);
	}
	sort(unHeard.begin(), unHeard.end());

	for(int i = 0; i < M; i++)
	{
		cin >> input;
		if (binarySearch(0, N-1, input)) result.push_back(input);
	}
	
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}