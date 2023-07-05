#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int result;
	int correct_cnt = 0, total_score = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> result;
		if (result == 1)
		{
			correct_cnt++;
			total_score += correct_cnt;
		}
		else
			correct_cnt = 0;
	}
	cout << total_score;

	return (0);
}
