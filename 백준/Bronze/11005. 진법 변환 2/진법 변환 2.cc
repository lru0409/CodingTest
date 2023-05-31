#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	int n, b; // 10진법 수 n을 b진법으로 변환
	cin >> n >> b;

	string result;
	while(n > 0)
	{
		if (n % b > 9)
			result += (n % b) + 'A' - 10;
		else
			result += (n % b) + '0';
		n /= b;
	}
	reverse(result.begin(), result.end());
	cout << result << endl;

	return (0);
}
