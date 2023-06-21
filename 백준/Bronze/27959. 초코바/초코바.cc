#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	if (100 * n >= m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	return (0);
}