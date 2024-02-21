#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

#define MAX 50

int N, L, R;
int A[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int BFS(int x, int y)
{
	vector<pair<int, int> > countries; // 연합을 이루는 나라들의 위치
	countries.push_back(make_pair(x, y));
	int total_p = A[x][y]; // 연합을 이루는 총 인구수

	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	visited[x][y] = true;

	while(!Q.empty())
	{
		int cx = Q.front().first, cy = Q.front().second;
		Q.pop();

		for(int i=0; i<4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if(visited[nx][ny])
				continue;
			int p_diff = abs(A[cx][cy] - A[nx][ny]); // 인구 수 차이
			if(p_diff < L || R < p_diff)
				continue;

			countries.push_back(make_pair(nx, ny));
			total_p += A[nx][ny];

			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	if(countries.size() == 1)
		return -1;

	int new_p = total_p / countries.size(); // 연합을 이루는 각 나라의 새로운 인구수
	for(size_t i=0; i<countries.size(); i++)
		A[countries[i].first][countries[i].second] = new_p;
	return 0;
}

int populationMovement()
{
	int ret = -1;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			visited[i][j] = false;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(visited[i][j])
				continue;
			if(BFS(i,j) == 0)
				ret = 0;
		}
	}
	return ret;
}

int main()
{
	cin >> N >> L >> R;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> A[i][j];

	int day = 0;
	while(1)
	{
		if (populationMovement() == -1)
			break;
		day++;
	}
	cout << day << '\n';

	return 0;
}