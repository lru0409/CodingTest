#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int L;
	cin >> L;

	string str;
	cin >> str;

	int M = 1234567891;
	long long sum = 0;
	long long r = 1;
	for(int i = 0; i < L; i++)
	{
		int num = str[i] - 96;
		sum = (sum + (num * r)) % M;
		r = (r * 31) % M;
	}
	cout << sum << endl;

	return (0);
}