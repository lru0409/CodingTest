#include <iostream>

using namespace std;

int main (void)
{
	int a, b;
	cin >> a >> b;

	int result1, result2, result3;
	result1 = a * (b % 10);
	result2 = a * ((b % 100) - (b % 10)) / 10;
	result3 = a * (b - (b % 100)) / 100;

	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;
	cout << result1 + result2*10 + result3*100 << endl;
	return (0);
}