#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string input;
	for(int i = 0; i < T; i++)
	{
		cin >> input;
		if (cin.eof()) break;
		int count = 0;
		for(int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(') count++;
			else count--;
			if (count < 0) break ;
		}
		if (count == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}