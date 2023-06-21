#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;

	if (a < b)
		cout << "Bus" << endl;
	else if (a > b)
		cout << "Subway" << endl;
	else
		cout << "Anything" << endl;
	
	return (0);
}