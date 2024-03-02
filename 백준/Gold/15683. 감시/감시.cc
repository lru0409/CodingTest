#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 8

#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE 2

int N, M;
char office[MAX][MAX];

int dx[4] = {0, -1, 0, 1}; // 좌상우하
int dy[4] = {-1, 0, 1, 0};

typedef struct cctv
{
	int pos_x;
	int pos_y;
	int type;
	vector<int> dir_idx;
} Cctv;

vector<Cctv> cctvs;
int blind_spot = 64;

void AddCctv(int x, int y)
{
	Cctv cctv;
	cctv.pos_x = x;
	cctv.pos_y = y;
	cctv.type = office[x][y] - '0';
	vector<int>& dirs = cctv.dir_idx;
	switch(cctv.type) {
		case 1: dirs.push_back(2); break;
		case 2: dirs.push_back(0); dirs.push_back(2); break;
		case 3: dirs.push_back(1); dirs.push_back(2); break;
		case 4: dirs.push_back(0); dirs.push_back(1); dirs.push_back(2); break;
		case 5: dirs.push_back(0); dirs.push_back(1); dirs.push_back(2); dirs.push_back(3); break;
	}
	cctvs.push_back(cctv);
}

void Input()
{
	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> office[i][j];
			if('1' <= office[i][j] && office[i][j] <= '5')
				AddCctv(i, j);
		}
	}
}

#define WALL '6'

int GetBlindSpot()
{
	// CCTV가 감시하는 방향을 #으로 표시하기
	for(size_t i=0; i<cctvs.size(); i++)
	{
		for(size_t j=0; j<cctvs[i].dir_idx.size(); j++)
		{
			int dir = cctvs[i].dir_idx[j];
			int cur_x = cctvs[i].pos_x, cur_y = cctvs[i].pos_y;
			while(true)
			{
				if(cur_x < 0 || cur_y < 0 || cur_x >= N || cur_y >= M)
					break;
				if(office[cur_x][cur_y] == WALL)
					break;
				if(office[cur_x][cur_y] < '1' || '5' < office[cur_x][cur_y])
					office[cur_x][cur_y] = '#';
				cur_x += dx[dir];
				cur_y += dy[dir];
			}
		}
	}

	// 사각지대의 크기를 세서 반환
	int count = 0;;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(office[i][j] == '0')
				count += 1;
		}
	}
	return count;
}

void rotateCctv(Cctv& cctv, int count, int rotation_dir)
{
	for(size_t i = 0; i<cctv.dir_idx.size(); i++)
	{
		if(rotation_dir == CLOCK_WISE)
		{
			cctv.dir_idx[i] += count;
			if(cctv.dir_idx[i] > 3)
				cctv.dir_idx[i] -= 4;
		}
		else // rotation_dir == COUNTER_CLOCK_WISE
		{
			cctv.dir_idx[i] -= count;
			if(cctv.dir_idx[i] < 0)
				cctv.dir_idx[i] += 4;
		}
	}
}

void Solve(int cctv)
{
	if(cctv == cctvs.size())
	{
		blind_spot = min(blind_spot, GetBlindSpot());
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(office[i][j] == '#')
					office[i][j] = '0';
			}
		}
		return;
	}

	for(int i=0; i<=3; i++)
	{
		rotateCctv(cctvs[cctv], i, CLOCK_WISE);
		Solve(cctv + 1);
		rotateCctv(cctvs[cctv], i, COUNTER_CLOCK_WISE);
	}
}

int main()
{
	Input();
	Solve(0);
	cout << blind_spot << "\n";

	return 0;
}