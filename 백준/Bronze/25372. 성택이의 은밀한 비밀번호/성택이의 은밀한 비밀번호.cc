#include <iostream>
using namespace std;

int main (void)
{
	int n;
	cin >> n;

	string str;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		if (6 <= str.length() && str.length() <= 9)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return (0);
}