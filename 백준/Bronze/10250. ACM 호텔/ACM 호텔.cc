#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int H, W, N;
	for(int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		// 층
		int floor = N % H;
		if (floor == 0) cout << H;
		else cout << floor;
		// 방 번호
		int roomNum = ((N - 1) / H) + 1;
		if (roomNum < 10) cout << 0;
		cout << roomNum << endl;
	}

	return 0;
}