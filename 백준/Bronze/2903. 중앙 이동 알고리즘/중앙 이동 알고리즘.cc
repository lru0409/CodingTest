#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	int n; // n번의 과정
	cin >> n;

	int c = 2; // 변의 길이
	int tmp = 1; // 다음 변의 길이와의 차이
	for(int i = 0; i < n; i++)
	{
		c += tmp;
		tmp *= 2;
	}
	cout << c * c << endl;

	return (0);
}