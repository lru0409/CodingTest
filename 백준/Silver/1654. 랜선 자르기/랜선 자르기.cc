#include <iostream>
#include <limits>
using namespace std;

int K, N;
int origin[10000];

bool isPossible(int len)
{
	int count = 0;
	for(int i = 0; i < K; i++)
		count += origin[i] / len;
	if (count >= N) return (true);
	return (false);
}

int getOptimalLen(int max)
{
	unsigned int start = 1;
	unsigned int end = max;

	int ret = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		// 랜선 길이를 mid로 맞출 때, N을 충족할 수 있는지 확인
		if (isPossible(mid)) // 가능다면 더 긴 길이도 되는지 확인
		{
			start = mid + 1;
			if (mid > ret) ret = mid;
		}
		else // 불가능하다면 더 짧은 길이로 시도
		{
			end = mid - 1;
		}
	}
	return (ret);
}

int main()
{
	cin >> K >> N;

	int max = 0;
	for(int i = 0; i < K; i++)
	{
		cin >> origin[i];
		if (origin[i] > max) max = origin[i];
	}

	cout << getOptimalLen(max) << endl;

	return (0);
}