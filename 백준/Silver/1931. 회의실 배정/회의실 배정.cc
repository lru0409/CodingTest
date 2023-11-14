#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ascending_end_time(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return (p1.first < p2.first);
	return (p1.second < p2.second);
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int> > meetings;
	int start, end;
	for(int i = 0; i < N; i++)
	{
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end(), ascending_end_time);

	int cur_end_time = meetings[0].second;
	int count = 1;
	for(int i = 1; i < N; i++)
	{
		if (meetings[i].first >= cur_end_time)
		{
			count += 1;
			cur_end_time = meetings[i].second;
		}
	}

	cout << count << endl;

	return (0);
}