#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int count[10000] = { 0, };
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		count[tmp - 1]++;
	}

	for(int i = 0; i < 10000; i++)
		for(int j = 0; j < count[i]; j++)
			cout << i + 1 << "\n";
	
	return (0);
}