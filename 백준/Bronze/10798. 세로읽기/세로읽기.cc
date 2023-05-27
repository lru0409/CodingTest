#include <iostream>

using namespace std;

int main (void)
{
	string input[5];

	for(int i = 0; i < 5; i++)
		getline(cin, input[i]);
	
	for(int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if (input[j].length() < i + 1)
				continue;
			cout << input[j][i];
		}
	}

	return (0);
}