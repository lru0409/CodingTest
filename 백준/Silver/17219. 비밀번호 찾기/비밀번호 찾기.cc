#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, string> Memo;
	for(int i = 0; i < N; i++)
	{
		string site, password;
		cin >> site >> password;
		Memo[site] = password;
	}

	for(int i = 0; i < M; i++)
	{
		string site;
		cin >> site;
		cout << Memo[site] << '\n';
	}

	return (0);
}