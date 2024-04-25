#include <string>
#include <vector>

using namespace std;

# define Y 0
# define X 1

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> dog_pos(2);
    
    for(int i = 0; i < park.size(); i++) {
        for(int j = 0; j < park[i].length(); j++) {
             if (park[i][j] == 'S') {
                 dog_pos[Y] = i;
                 dog_pos[X] = j;
             }       
        }
    }
            
    for(string route : routes)
    {
        // 이동 방향, 거리 구하기
        int dir, count;
        switch(route[0]) {
            case 'E': dir = 0; break;
            case 'W': dir = 1; break;
            case 'S': dir = 2; break;
            case 'N': dir = 3; break;
        }
        count = route[2] - '0';
        
        // 공원을 벗어나거나 장애물을 만날 때까지, dir 방향으로 count번 이동
        vector<int> next_pos(dog_pos);
        while (count--)
        {
            next_pos[Y] += dy[dir];
            next_pos[X] += dx[dir];
            if (next_pos[Y] < 0 || next_pos[X] < 0 || 
                next_pos[Y] >= park.size() || next_pos[X] >= park[0].size())
                break;
            if (park[next_pos[Y]][next_pos[X]] == 'X')
                break;
        }
        if (count < 0) // count번 정상적으로 이동했다면, 현재 강아지 위치 갱신
            dog_pos = next_pos;
    }

    return dog_pos;
}