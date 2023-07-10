#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
		return (p1.second < p2.second);
	return (p1.first < p2.first);
}

int main (void)
{
	ios_base::sync_with_stdio(false);

	int	n;
	cin >> n;

	vector< pair<int, int> > points;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	sort(points.begin(), points.end(), compare);

	for(int i = 0; i < n; i++)
		cout << points[i].first << " " << points[i].second << "\n";

	return (0);
}