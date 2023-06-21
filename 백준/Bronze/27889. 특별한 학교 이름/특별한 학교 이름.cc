#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	if (input == "NLCS")
		cout << "North London Collegiate School" << endl;
	else if (input == "BHA")
		cout << "Branksome Hall Asia" << endl;
	else if (input == "KIS")
		cout << "Korea International School" << endl;
	else
		cout << "St. Johnsbury Academy" << endl;
	
	return (0);
}