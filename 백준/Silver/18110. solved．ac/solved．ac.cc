#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << endl;
		return (0);
	}

	int except = round(n * 0.15);

	int difficulty[300000];
	for(int i = 0; i < n; i++)
		cin >> difficulty[i];
	sort(difficulty, difficulty + n);

	double sum = 0;
	for(int i = except; i < n - except; i++)
		sum += difficulty[i];
	cout << round(sum / (n - (except * 2))) << endl;

	return (0);
}