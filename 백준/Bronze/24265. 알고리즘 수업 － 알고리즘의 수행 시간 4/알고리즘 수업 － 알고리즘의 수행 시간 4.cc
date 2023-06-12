#include <iostream>

using namespace std;

int main (void)
{
	long long int n;
	cin >> n;

	long long int count = 0; // 수행 횟수
	for(long long int i = 1; i < n; i++)
		count += i;

	cout << count << "\n" << 2 << "\n";
	return (0);
}