#include <iostream>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> FindByName;
	vector<string> FindByNumber;
	for(int i = 1; i <= N; i++)
	{
		string pocketmon;
		cin >> pocketmon;
		FindByName[pocketmon] = i;
		FindByNumber.push_back(pocketmon);
	}
	for(int i = 1; i <= M; i++)
	{
		string question;
		cin >> question;
		if (isdigit(question[0]))
		{
			cout << FindByNumber[stoi(question) - 1] << '\n';
		}
		else
		{
			cout << FindByName[question] << '\n';
		}
	}

	return (0);
}