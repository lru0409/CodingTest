#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define KOREAN 0
#define ENGLISH 1
#define MATH 2

bool comp(pair<string, vector<int> > s1, pair<string, vector<int> > s2)
{
	if (s1.second[KOREAN] != s2.second[KOREAN])
		return s1.second[KOREAN] > s2.second[KOREAN];
	if (s1.second[ENGLISH] != s2.second[ENGLISH])
		return s1.second[ENGLISH] < s2.second[ENGLISH];
	if (s1.second[MATH] != s2.second[MATH])
		return s1.second[MATH] > s2.second[MATH];
	return s1.first < s2.first;
}

int main()
{
	int N;
	cin >> N;

	string name;
	vector<int> scores(3);
	vector<pair<string, vector<int> > > students;
	for(int i = 0; i < N; i++)
	{
		cin >> name;
		for(int j = 0; j < 3; j++)
			cin >> scores[j];
		students.push_back(make_pair(name, scores));
	}

	sort(students.begin(), students.end(), comp);

	for(int i = 0; i < N; i++)
		cout << students[i].first << '\n';
	
	return 0;
}