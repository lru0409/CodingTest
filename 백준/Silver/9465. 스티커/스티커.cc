#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, sticker[2][100000];
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> n;
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < n; k++)
				cin >> sticker[j][k];
		}

		sticker[0][1] += sticker[1][0];
		sticker[1][1] += sticker[0][0];
		for(int j = 2; j < n; j++) {
			sticker[0][j] += max(sticker[1][j - 1], sticker[1][j - 2]);
			sticker[1][j] += max(sticker[0][j - 1], sticker[0][j - 2]);
		}

		cout << max(sticker[0][n - 1], sticker[1][n - 1]) << '\n';
	}

	return (0);
}
