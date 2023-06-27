#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int h1, m1, s1, h2, m2, s2;
	int a, b, c ;
	for(int i = 0; i < 3; i++)
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		a = h1 * 3600 + m1 * 60 + s1;
		b = h2 * 3600 + m2 * 60 + s2;
		c = b - a;
		cout << c / 3600 << " ";
		c %= 3600;
		cout << c / 60 << " ";
		c %= 60;
		cout << c << "\n";
	}

	return (0);
}
