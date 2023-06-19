#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int count = 0;
	int num = 1;
	int tmp, cnt;
	while (1)
	{
		tmp = num;
		cnt = 0;
		while (tmp)
		{
			if (tmp % 10 == 6)
				cnt++;
			else
				cnt = 0;
			if (cnt >= 3)
			{
				count++;
				break ;
			}
			tmp /= 10;
		}
		if (count == n)
			break;
		num++;
	}
	cout << num << endl;

	return (0);
}