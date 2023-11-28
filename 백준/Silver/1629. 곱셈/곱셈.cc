#include <iostream>
using namespace std;

long long A, B, C;

int power(int n)
{
	if (n == 1)
		return (A % C);
	
	long long ret = power(n/2);
	if (n % 2 == 0)
		return (ret * ret % C);
	else
		return (ret * ret % C * A % C);
}

int main()
{
	cin >> A >> B >> C;
	cout << power(B) << '\n';

	return (0);
}
