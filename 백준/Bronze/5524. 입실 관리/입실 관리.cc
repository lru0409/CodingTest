#include <iostream>
#include <cctype>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string name;
	for(int i = 0; i < n; i++)
	{
		cin >> name;
		for(int j = 0; j < name.length(); j++)
			name[j] = tolower(name[j]);
		cout << name << "\n";
	}

	return (0);
}
