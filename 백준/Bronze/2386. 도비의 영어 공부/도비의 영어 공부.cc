#include <iostream>
using namespace std;

int main(void)
{
	char c;
	string str;

	while(1)
	{
		cin >> c;
		if (c == '#') break;
		getline(cin, str);

		int count = 0;
		for(int i = 0; i < str.length(); i++)
		{
			if (c == str[i] || c -'a' + 'A' == str[i])
				count += 1;
		}

		cout << c << " " << count << endl;
	}

	return (0);
}
