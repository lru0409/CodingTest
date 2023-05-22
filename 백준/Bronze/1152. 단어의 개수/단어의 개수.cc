#include <iostream>
#include <string.h>

using namespace std;

int main (void)
{
	string input;
	getline(cin, input);

	int count = 0;
	int flag = true;
	for(int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ') {
			flag = true;
		} else if (flag) {
			count++;
			flag = false;
		}
	}
	cout << count;

	return (0);
}