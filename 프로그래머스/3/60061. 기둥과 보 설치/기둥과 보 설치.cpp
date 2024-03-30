#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define PILLAR 0
#define BEAM 1

#define REMOVE 0
#define INSTALL 1

bool wall[101][101][2];

bool check_build(int x, int y, int type, int n)
{
    if (type == PILLAR) { // 기둥
        if (y == 0) return true; // 바닥 위
        if (wall[x][y][BEAM]) return true; // 보 왼쪽 끝 위
        if (0 <= x-1 && wall[x-1][y][BEAM]) return true; // 보 오른쪽 끝 위
        if (0 <= y-1 && wall[x][y-1][PILLAR]) return true; // 기둥 위
    }
    else { // 보
        if (0 <= x-1 && wall[x-1][y][BEAM] && x+1 <= n && wall[x+1][y][BEAM]) return true; // 양쪽 끝 보
        if (0 <= y-1 && wall[x][y-1][PILLAR]) return true; // 왼쪽 아래 기둥
        if (0 <= y-1 && x+1 <= n && wall[x+1][y-1][PILLAR]) return true; // 오른쪽 아래 기둥
    }
    return false;
}

bool check_remove(int x, int y, int type, int n)
{
    wall[x][y][type] = false;
    if (type == PILLAR) { // 기둥
		// 위의 기둥
		if (y+1 <= n && wall[x][y+1][PILLAR] && !check_build(x, y+1, PILLAR, n)) return false;
		// 위의 좌우 보
		if (y+1 <= n && wall[x-1][y+1][BEAM] && !check_build(x-1, y+1, BEAM, n)) return false;
        if (y+1 <= n && wall[x][y+1][BEAM] && !check_build(x, y+1, BEAM, n)) return false; 
    }
    else { // 보
		// 위의 좌우 기둥
		if (wall[x][y][PILLAR] && !check_build(x, y, PILLAR, n)) return false;
		if (x+1 <= n && wall[x+1][y][PILLAR] && !check_build(x+1, y, PILLAR, n)) return false;
		// 좌우 보
		if (0 <= x-1 && wall[x-1][y][BEAM] && !check_build(x-1, y, BEAM, n)) return false;
		if (x+1 <= n && wall[x+1][y][BEAM] && !check_build(x+1, y, BEAM, n)) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{    
	for(int i = 0; i < build_frame.size(); i++)
	{
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2];
        int work = build_frame[i][3];
        
        if (work == REMOVE) {	// 제거 작업
            if (check_remove(x, y, type, n) == false)
                wall[x][y][type] = true;
        } else {				// 설치 작업
            if (check_build(x, y, type, n))
                wall[x][y][type] = true;
        }
    }
    
	vector<vector<int>> answer;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
			if (wall[i][j][PILLAR])
				answer.push_back({i, j, PILLAR});
			if (wall[i][j][BEAM])
				answer.push_back({i, j, BEAM});
        }
    }
    return answer;
}
