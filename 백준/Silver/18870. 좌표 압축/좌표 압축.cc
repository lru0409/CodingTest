#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> origin;
	for(int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		origin.push_back(input);
	}

	vector<int> sorted(origin);
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for(int i = 0; i < n; i++)
	{
		auto it = lower_bound(sorted.begin(), sorted.end(), origin[i]);
		cout << it - sorted.begin() << " ";
	}

	return (0);
}