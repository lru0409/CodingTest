#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	if (input == "SONGDO")
		cout << "HIGHSCHOOL" << endl;
	else if (input == "CODE")
		cout << "MASTER" << endl;
	else if (input == "2023")
		cout << "0611" << endl;
	else
		cout << "CONTEST" << endl;
	
	return (0);
}