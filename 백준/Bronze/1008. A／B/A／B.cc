#include <iostream>

using namespace std;

int main (void)
{
	double a, b;

	cin >> a >> b;

	cout << fixed; // 소수점 아래부터 유효숫자를 셈
	cout.precision(9); // 유효숫자 표기 명령
	cout << a / b;

	return (0);
}