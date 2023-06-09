#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	int len[3];
	cin >> len[0] >> len[1] >> len[2];

	sort(len, len + 3);
	int sum = len[0] + len[1] + len[2];

	if (len[2] < len[0] + len[1])
	{
		cout << sum << endl;
		return (0);
	}
	cout << sum - (len[2] - (len[0] + len[1]) + 1) << endl;
	return (0);
}