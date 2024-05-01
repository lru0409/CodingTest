#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define RIGHT 0
#define DOWN 1

#define FIRST_Y 0
#define FIRST_X 1
#define SECOND_Y 2
#define SECOND_X 3
#define TIME 4

#define UP_LEFT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define DOWN_RIGHT 3

#define WALL 1

int N;
vector<vector<int>> map;
bool visited[100][100][2] = { false, }; // 우, 하
queue<vector<int>> Q;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int ho_rotate[4][4] = {
    { -1, -1, 0, 0 },
    { 0, 1, 0, 1 },
    { 0, 0, 1, 1 },
    { -1, 0, -1, 0 }
};
int ver_rotate[4][4] = {
    { 0, 0, 1, 1 },
    { -1, 0, -1, 0 },
    { -1, -1, 0, 0 },
    { 0, 1, 0, 1 }
};
int ho_rotate_check[2][4] = {
    { -1, -1, 1, 1 },
    { 1, 0, 1, 0 }
};
int ver_rotate_check[2][4] = {
    { 1, 1, 0, 0 },
    { -1, 1, -1, 1 }
};

int getDir(int y1, int y2)
{
    if (abs(y1 - y2) > 0)
        return DOWN;
    return RIGHT;
}

void move(vector<int> current, int dir)
{
    for(int i = 0; i < 4; i++)
    {
        int ny1 = current[FIRST_Y] + dy[i], nx1 = current[FIRST_X] + dx[i];
        int ny2 = current[SECOND_Y] + dy[i], nx2 = current[SECOND_X] + dx[i];
        if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0 ||
            ny1 >= N || nx1 >= N || ny2 >= N || nx2 >= N)
            continue;
        if (map[ny1][nx1] == WALL || map[ny2][nx2] == WALL)
            continue;
        if (visited[ny1][nx1][dir])
            continue;
        Q.push({ny1, nx1, ny2, nx2, current[TIME] + 1});
        visited[ny1][nx1][dir] = true;
    }
}

void rotate(vector<int> current, int dir)
{
    int ny1, nx1, ny2, nx2;
    int check_y, check_x;
    int rotate_dir = dir == RIGHT ? DOWN : RIGHT;
    for(int i = 0; i < 4; i++)
    {
        if (dir == RIGHT) {
            ny1 = current[FIRST_Y] + ho_rotate[FIRST_Y][i];
            nx1 = current[FIRST_X] + ho_rotate[FIRST_X][i];
            ny2 = current[SECOND_Y] + ho_rotate[SECOND_Y][i];
            nx2 = current[SECOND_X] + ho_rotate[SECOND_X][i];
        } else { // DOWN
            ny1 = current[FIRST_Y] + ver_rotate[FIRST_Y][i];
            nx1 = current[FIRST_X] + ver_rotate[FIRST_X][i];
            ny2 = current[SECOND_Y] + ver_rotate[SECOND_Y][i];
            nx2 = current[SECOND_X] + ver_rotate[SECOND_X][i];
        }
        if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0 ||
            ny1 >= N || nx1 >= N || ny2 >= N || nx2 >= N)
            continue;
        if (dir == RIGHT) {
            check_y = current[FIRST_Y] + ho_rotate_check[0][i];
            check_x = current[FIRST_X] + ho_rotate_check[1][i];
        } else { // DOWN
            check_y = current[FIRST_Y] + ver_rotate_check[0][i];
            check_x = current[FIRST_X] + ver_rotate_check[1][i];
        }
        if (map[check_y][check_x] == WALL || map[ny1][nx1] == WALL || map[ny2][nx2] == WALL)
            continue;
        if (visited[ny1][nx1][rotate_dir])
            continue;
        Q.push({ny1, nx1, ny2, nx2, current[TIME] + 1});
        visited[ny1][nx1][rotate_dir] = true;
    }
}

int BFS()
{
    Q.push({0, 0, 0, 1, 0});
    visited[0][0][RIGHT] = true;
    
    while (!Q.empty())
    {
        vector<int> current = Q.front();
        int dir = getDir(current[FIRST_Y], current[SECOND_Y]);
        Q.pop();
        
        if ((current[FIRST_Y] == N-1 && current[FIRST_X] == N-1) ||
            (current[SECOND_Y] == N-1 && current[SECOND_X] == N-1))
            return current[TIME];
        
        move(current, dir); // 상하좌우
        rotate(current, dir); // 위왼, 위오, 아래왼, 아래오 회전
    }
    return -1;
}

int solution(vector<vector<int>> board)
{
    N = board.size();
    map = board;
    return BFS();
}