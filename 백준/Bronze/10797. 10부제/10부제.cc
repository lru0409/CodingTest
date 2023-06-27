#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int day, carNum;
	int count = 0;

	cin >> day;
	for(int i = 0; i < 5; i++)
	{
		cin >> carNum;
		if (carNum == day)
			count++;
	}
	cout << count;

	return (0);
}
