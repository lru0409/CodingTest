#include <iostream>

using namespace std;

int main (void)
{
	int	n; // n개의 수가 주어짐
	cin >> n;

	int	num; // 주어지는 수
	int	result = 0; // 소수의 개수
	int	count; // 약수의 개수
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		count = 0;
		for(int i = 1; i <= num; i++)
		{
			if (num % i == 0)
				count++;
		}
		if (count == 2)
			result++;
	}
	cout << result;

	return (0);
}