#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	int age, weight;
	while (1)
	{
		cin >> name >> age >> weight;
		if (name == "#")
			break ;

		if (age > 17 || weight >= 80)
			cout << name << " Senior" << endl;
		else
			cout << name << " Junior" << endl;
	}

	return (0);
}