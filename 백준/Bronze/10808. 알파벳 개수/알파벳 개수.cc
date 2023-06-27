#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int alphaCnt[26] = { 0, };
	string input;
	cin >> input;

	for(int i = 0; i < input.length(); i++)
		alphaCnt[input[i] - 'a'] += 1;
	
	for(int i = 0; i < 26; i++)
		cout << alphaCnt[i] << " ";

	return (0);
}
