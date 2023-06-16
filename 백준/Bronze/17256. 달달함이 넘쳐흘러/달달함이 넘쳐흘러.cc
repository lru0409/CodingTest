#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	
	int a[3], c[3];
	cin >> a[0] >> a[1] >> a[2];
	cin >> c[0] >> c[1] >> c[2];
	cout << c[0] - a[2] << " " << c[1] / a[1] << " " << c[2] - a[0] << endl;
	return (0);
}