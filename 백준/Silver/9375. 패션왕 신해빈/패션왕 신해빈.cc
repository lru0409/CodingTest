#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	string name, category;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		map<string, int> M;
		for(int j = 0; j < n; j++)
		{
			cin >> name >> category;
			M[category] += 1;
		}

		int result = 1;
		for(map<string, int>::iterator iter = M.begin(); iter != M.end(); iter++)
			result *= (iter->second + 1);
		result -= 1;
		cout << result << '\n';
	}

	return (0);
}