#include <iostream>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	int a[10000];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum == m) count++;
		}
	}
	cout << count << endl;

	return (0);
}