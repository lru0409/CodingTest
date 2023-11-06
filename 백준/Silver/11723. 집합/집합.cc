#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V;

int check(int x)
{
	vector<int>::iterator iter;
	iter = find(V.begin(), V.end(), x);
	if (iter == V.end()) return (0);
	return (1);
}

void add(int x)
{
	if (check(x)) return ;
	V.push_back(x);
}

void remove(int x)
{
	V.erase(remove(V.begin(), V.end(), x), V.end());
}

void toggle(int x)
{
	if (check(x)) remove(x);
	else add(x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;
	string cmd;
	int x;
	for(int i = 0; i < M; i++)
	{
		cin >> cmd;

		if (cmd == "all" || cmd == "empty") {
			V.clear();
			if (cmd == "all") for(int i = 1; i <= 20; i++) V.push_back(i);
			continue;
		}

		cin >> x;
		if (cmd == "add") add(x);
		else if (cmd == "remove") remove(x);
		else if (cmd == "check") cout << check(x) << '\n';
		else if (cmd == "toggle") toggle(x);
	}

	return (0);
}