#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b, c; // 현재 시각 시, 분, 초
	int d; // 요리하는 데 필요한 시간(초)
	cin >> a >> b >> c >> d;

	c += d;
	b += c / 60;
	a += b / 60;

	cout << a % 24 << " " << b % 60 << " " << c % 60 << endl;
	return (0);
}