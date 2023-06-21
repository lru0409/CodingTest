#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int x, n; // 총 금액, 물건의 종류 수
	cin >> x >> n;

	int a, b; // 물건의 가격, 개수
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == x)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	
	return (0);
}