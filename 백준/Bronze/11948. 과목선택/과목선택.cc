#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int scores1[4], scores2[2];
	cin >> scores1[0] >> scores1[1] >> scores1[2] >> scores1[3];
	cin >> scores2[0] >> scores2[1];

	sort(scores1, scores1 + 4);
	sort(scores2, scores2 + 2);

	cout << scores1[1] + scores1[2] + scores1[3] + scores2[1];

	return (0);
}
