#include <iostream>

using namespace std;

int main (void)
{
	int count;
	cin >> count;

	string str;
	for(int i = 0; i < count; i++)
	{
		cin >> str;
		cout << str[0] << str[str.length() - 1] << endl;
	}

	return (0);
}