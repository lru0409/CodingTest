#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	pair<int, int> arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for(int i = 0; i < n; i++)
	{
		int count = 0; // 자신보다 덩치가 더 큰 사람의 수
		for(int j = 0; j < n; j++)
		{
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				count++;
		}
		cout << count + 1 << " ";
	}
	
	return (0);
}