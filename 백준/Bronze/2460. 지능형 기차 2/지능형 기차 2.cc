#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int max = -1;
	int	cur = 0;
	int a, b;
	for(int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		cur -= a;
		cur += b;
		if (cur > max)
			max = cur;
	}
	cout << max;
	
	return (0);
}
