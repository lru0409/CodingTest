#include <iostream>

using namespace std;

int main (void)
{
	string input;
	cin >> input;

	for(int i = 0; i < input.length(); i++)
	{
		if (input[i] != input[input.length() - i - 1])
		{
			cout << "0" << endl;
			return (0);
		}
	}
	cout << "1" << endl;
	return (0);
}
