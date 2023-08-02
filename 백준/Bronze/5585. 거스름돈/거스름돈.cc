#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int money[6] = { 500, 100, 50, 10, 5, 1};

	int cost;
	cin >> cost;
	int change = 1000 - cost;

	int count = 0;
	for(int i = 0; i < 6; i++)
	{
		count += change / money[i];
		change %= money[i];
	}
	cout << count;
	
	return (0);
}
