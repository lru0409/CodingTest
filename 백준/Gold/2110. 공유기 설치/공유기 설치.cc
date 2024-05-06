// 1 2   4       8 9
// 1 2 3 4 5 6 7 8 9

// 1 2 3 4 5 6 7 8 9 10

// 최대 : 첫집과 끝집 사이
// 최소 : 1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;

	vector<int> houses(N);
	for(int i = 0; i < N; i++)
		cin >> houses[i];
	sort(houses.begin(), houses.end());

	int start = 1, end = houses[N-1] - houses[0];
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int prev = houses[0], cnt = 1;
		for(int i = 1; i < N; i++)
		{
			if (houses[i] - prev >= mid) {
				cnt += 1;
				prev = houses[i];
			}
		}
		if (cnt >= C)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << end << '\n';

	return 0;
}