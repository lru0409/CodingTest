#include <iostream>
#include <algorithm>

#define R 0
#define G 1
#define B 2

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int r, g, b;
	int mini[1001][3];
	mini[0][0] = 0;
	mini[0][1] = 0;
	mini[0][2] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> r >> g >> b;
		mini[i][R] = min(mini[i-1][G], mini[i-1][B]) + r;
		mini[i][G] = min(mini[i-1][R], mini[i-1][B]) + g;
		mini[i][B] = min(mini[i-1][R], mini[i-1][G]) + b;
	}
	cout << min(mini[n][R], min(mini[n][G], mini[n][B]));
	
	return (0);
}
