#include <iostream>
using namespace std;

// 팩토리얼 : 그 수보다 작거나 같은 모든 양의 정수의 곱

int main (void)
{
	int n;
	cin >> n;

	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	cout << result;

	return (0);
}