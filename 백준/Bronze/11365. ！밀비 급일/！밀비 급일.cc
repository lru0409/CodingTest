#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	while (1)
	{
		getline(cin, input);
		if (input == "END")
			break ;
		for(int i = input.length() - 1; i >= 0; i--)
			cout << input[i];
		cout << "\n";
	}

	return (0);
}
