#include <iostream>
using namespace std;

int main(void)
{
	string input1, input2;
	cin >> input1 >> input2;

	if (input1.length() < input2.length())
		cout << "no";
	else
		cout << "go";

	return (0);
}