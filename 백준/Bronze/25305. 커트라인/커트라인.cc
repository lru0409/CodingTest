#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int scores[n];
	for(int i = 0; i < n; i++)
		cin >> scores[i];
	
	for(int i = 0; i < n - 1; i++)
	{
		int max_idx = i;
		for(int j = i + 1; j < n; j++)
		{
			if (scores[j] > scores[max_idx])
				max_idx = j;
		}
		swap(scores[i], scores[max_idx]);
	}
	cout << scores[k - 1];
	
	return (0);
}