#include <iostream>
// #include <queue>
// #include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10

int N, M, K; // 땅 크기, 나무 개수, K년 후
int A[MAX][MAX];
// multiset<int> trees[MAX][MAX];
vector<int> trees[MAX][MAX];
int nutrient[MAX][MAX];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void Input()
{
	cin >> N >> M >> K;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> A[i][j];
			nutrient[i][j] = 5;
		}
	}
	int x, y, z;
	for(int i=0; i<M; i++) {
		cin >> x >> y >> z;
		// trees[x-1][y-1].insert(z);
		trees[x-1][y-1].push_back(z);
	}
}

void SpringAndSummer()
{
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			if(trees[x][y].size() == 0)
				continue;
			sort(trees[x][y].begin(), trees[x][y].end());
			vector<int> alive;
			int die_nutrient = 0;
			for(size_t i=0; i<trees[x][y].size(); i++)
			{
				int age = trees[x][y][i];
				if (age > nutrient[x][y]) { // 양분이 부족한 경우
					die_nutrient += age / 2;
				} else { // 양분이 부족하지 않은 경우
					nutrient[x][y] -= age;
					alive.push_back(age + 1);
				}
			}
			trees[x][y].clear();
			for(size_t i=0; i<alive.size(); i++) // 죽지 않은 나무들의 나이 + 1
				trees[x][y].push_back(alive[i]);
				// trees[x][y].insert(alive[i]);
			nutrient[x][y] += die_nutrient;
		}
	}
}

void FallAndWinter()
{
	int nx, ny;
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			for(size_t i=0; i<trees[x][y].size(); i++)
			{
				if(trees[x][y][i] % 5 != 0)
					continue;
				for(int j=0; j<8; j++)
				{
					nx = x + dx[j], ny = y + dy[j];
					if(nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					trees[nx][ny].push_back(1);
				}
			}
			nutrient[x][y] += A[x][y];
		}
	}
}

void Simulation()
{
	for(int year=0; year<K; year++)
	{
		SpringAndSummer();
		FallAndWinter();
	}
}

void Output()
{
	int ret = 0;
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			ret += trees[x][y].size();
		}
	}
	cout << ret << '\n'; // 나무의 개수 출력
}

int main()
{
	Input();
	Simulation();
	Output();
	return 0;
}