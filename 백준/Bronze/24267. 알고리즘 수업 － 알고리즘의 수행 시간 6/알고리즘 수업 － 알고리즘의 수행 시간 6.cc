#include <iostream>

using namespace std;

int main (void)
{
	long long int n;
	cin >> n;

	long long int count = 0; // 실행 횟수
	for(long long int i = 1; i <= n - 2; i++)
		count += (i * (i + 1))/2;

	cout << count << "\n" << 3 << "\n";
	return (0);
}