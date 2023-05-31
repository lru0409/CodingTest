#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	int count;
	cin >> count;

	int c; // 거스름돈
	int val[4] = { 25, 10, 5, 1 }; // 각 동전의 값
	for(int i = 0; i < count; i++)
	{
		cin >> c;
		for(int j = 0; j < 4; j++)
		{
			cout << c / val[j] << " ";
			c %= val[j];
		}
		cout << endl;
	}

	return (0);
}
