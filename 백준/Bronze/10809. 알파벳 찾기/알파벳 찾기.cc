#include <iostream>

using namespace std;

int main (void)
{
	string s;
	string alphabets = "abcdefghijklmnopqrstuvwxyz";

	cin >> s;

	for(int i = 0; i < alphabets.length(); i++)
		cout << (int)s.find(alphabets[i]) << " ";

	return (0);
}