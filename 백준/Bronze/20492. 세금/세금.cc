#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	cout << n - (n * 22/100) << " ";
	cout << n - ((n * 20/100) * 22/100) << endl;
	return (0);
}