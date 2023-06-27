#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int sum, dif, aScore, bScore;
	cin >> sum >> dif;

	if (sum < dif)
	{
		cout << "-1";
		return (0);
	}

	aScore = (sum + dif) / 2;
	bScore = (sum - dif) / 2;

	if (aScore + bScore == sum && aScore - bScore == dif) {
		cout << aScore << " " << bScore;
	} else {
		cout << "-1";
	}

	return (0);
}
