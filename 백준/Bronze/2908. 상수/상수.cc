#include <iostream>

using namespace std;

int main (void)
{
	string num1, num2;
	cin >> num1 >> num2;

	int i;
	for(i = 2; i >= 0; i--)
		if (num1[i] != num2[i]) break;

	string bigger;
	if (num1[i] > num2[i])
		bigger = num1;
	else
		bigger = num2;

	cout << bigger[2] << bigger[1] << bigger[0] << endl;
	return (0);
}