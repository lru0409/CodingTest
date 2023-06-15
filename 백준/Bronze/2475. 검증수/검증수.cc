#include <iostream>
using namespace std;

int main(void)
{
	int sum = 0, tmp;

	for(int i = 0; i < 5; i++)
	{
		cin >> tmp;
		sum += tmp*tmp;
	}
	cout << sum % 10 << endl;
	return (0);
}