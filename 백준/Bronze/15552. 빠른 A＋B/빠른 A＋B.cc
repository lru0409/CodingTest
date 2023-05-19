#include <iostream>

using namespace std;

int main (void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
}