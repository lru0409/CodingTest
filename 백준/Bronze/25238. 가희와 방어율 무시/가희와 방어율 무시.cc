#include <iostream>
using namespace std;

int main(void)
{
	double a, b; // 방어율, 방무
	cin >> a >> b;

	double c = a - (a * b/100); // 체감 방어율
	if (c < 100)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	return (0);
}