#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, input;
	cin >> n;

	vector<vector<int> > triangle(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> input;
			triangle[i].push_back(input);
		}
	}

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
				triangle[i][j] += triangle[i-1][j];
			else if (j == triangle[i].size()-1)
				triangle[i][j] += triangle[i-1][j-1];
			else
				triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
		}
	}

	int answer = 0;
	for(int i = 0; i < triangle[n-1].size(); i++)
		answer = max(answer, triangle[n-1][i]);
	cout << answer << '\n';

	return 0;
}
