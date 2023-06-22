#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int num[3];
	cin >> num[0] >> num[1] >> num[2];

	sort(num, num + 3);
	cout << num[0] << " " << num[1] << " " << num[2];

	return (0);
}