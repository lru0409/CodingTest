#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	string input;
	for(int i = 1; i <= n; i++)
	{
		getline(cin, input);
		cout << i << ". " << input << "\n";
	}

	return (0);
}
