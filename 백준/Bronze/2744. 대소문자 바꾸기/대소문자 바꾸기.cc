#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;
	
	for(int i = 0; i < input.length(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
			input[i] += 32;
		else
			input[i] -= 32;
	}
	cout << input;

	return (0);
}