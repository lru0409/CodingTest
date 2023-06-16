#include <iostream>
using namespace std;

int main (void)
{
	int l;
	cin >> l;

	int result = l/5;
	if (l%5 != 0)
		result += 1;
	cout << result << endl;

	return (0);
}