#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	
	sort(p, p + n);

	int total = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			total += p[j];
	cout << total;
	
	return (0);
}
