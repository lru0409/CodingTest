#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int score;
	int sum = 0;
	for(int i = 0; i < 5; i++)
	{
		cin >> score;
		if (score < 40)
			sum += 40;
		else
			sum += score;
	}
	cout << sum / 5;

	return (0);
}
