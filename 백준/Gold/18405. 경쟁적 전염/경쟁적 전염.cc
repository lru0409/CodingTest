#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 200
#define EMPTY 0

int N, K; // 시험관 크기, 바이러스 종류
int S, X, Y; // S초 후에 (X,Y)에 존재하는 바이러스 종류
int examiner[MAX][MAX]; // 시험관

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(vector<pair<int, pair<int, int> > >& virus)
{
	queue<pair<int, pair<int, int> > > Q;
	for(size_t i = 0; i < virus.size(); i++)
		Q.push(make_pair(0, make_pair(virus[i].second.first, virus[i].second.second)));

	while (!Q.empty()) {
		int time = Q.front().first;
		int cy = Q.front().second.first;
		int cx = Q.front().second.second;
		Q.pop();

		if (S == time)
			break;
		
		for(int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (examiner[ny][nx] != EMPTY)
				continue;
			examiner[ny][nx] = examiner[cy][cx];
			Q.push(make_pair(time + 1, make_pair(ny, nx)));
		}
	}
}

int main()
{
	vector<pair<int, pair<int, int> > > virus; // 타입, 위치

	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> examiner[i][j];
			if (examiner[i][j] > EMPTY)
				virus.push_back(make_pair(examiner[i][j], make_pair(i, j)));
		}
	}
	cin >> S >> X >> Y;

	sort(virus.begin(), virus.end());
	BFS(virus);
	cout << examiner[X-1][Y-1] << '\n';

	return 0;
}