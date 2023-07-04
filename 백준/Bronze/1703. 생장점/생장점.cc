#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, count;
	while (1)
	{
		count = 1;
		cin >> a;
		if (a == 0)
			break ;
		
		int s, r;
		for(int i = 0; i < a; i++)
		{
			cin >> s >> r;
			count = count * s - r;
		}
		cout << count << "\n";
	}
	
	return (0);
}
