#include <iostream>
using namespace std;

int paper[128][128];
int white_paper = 0, blue_paper = 0;

void split_paper(int N, int x, int y)
{
	int white_square = 0, blue_square = 0;
	for(int i = x; i < x + N; i++) {
		for(int j = y; j < y + N; j++) {
			if (paper[i][j]) blue_square++;
			else white_square++;
		}
	}
	if (white_square == N * N) {
		white_paper++;
		return;
	}
	if (blue_square == N * N) {
		blue_paper++;
		return;
	}

	split_paper(N/2, x, y);
	split_paper(N/2, x + N/2, y);
	split_paper(N/2, x, y + N/2);
	split_paper(N/2, x + N/2, y + N/2);
}

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> paper[i][j];

	split_paper(N, 0, 0);
	cout << white_paper << endl;
	cout << blue_paper << endl;

	return (0);
}