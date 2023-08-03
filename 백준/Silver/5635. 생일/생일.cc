#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector< pair< pair<int, int>, pair<int, string> > > student(n);
	for(int i = 0; i < n; i++)
		cin >> student[i].second.second >> student[i].second.first >> student[i].first.second >> student[i].first.first;

	sort(student.begin(), student.end());

	cout << student[n-1].second.second << '\n' << student[0].second.second << '\n';
	return (0);
}