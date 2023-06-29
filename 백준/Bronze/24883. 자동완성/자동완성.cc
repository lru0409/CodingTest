#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	char input;
	cin >> input;

	if (input == 'N' || input == 'n')
		cout << "Naver D2";
	else
		cout << "Naver Whale";

	return (0);
}
