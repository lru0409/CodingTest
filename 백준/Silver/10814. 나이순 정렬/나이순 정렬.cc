#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> m1, pair<int, string> m2)
{
	return (m1.first < m2.first);
}

int main(void)
{
	int n;
	cin >> n;

	vector < pair<int, string> > members;
	for(int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		members.push_back(make_pair(age, name));
	}

	stable_sort(members.begin(), members.end(), compare);

	for(int i = 0; i < n; i++)
		cout << members[i].first << " " << members[i].second << "\n";

	return (0);
}