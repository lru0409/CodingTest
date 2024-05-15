#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

#define TOP 0
#define LEFT 1
#define BOTTOM 2
#define RIGHT 3

vector<int> solution(vector<string> wallpaper)
{
    vector<int> pos(4);
    pos[TOP] = 50;
    pos[LEFT] = 50;
    pos[RIGHT] = 0;
    
    for(int i = 0; i < wallpaper.size(); i++) {
        for(int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] != '#')
                continue;
            pos[TOP] = min(pos[TOP], i);
            pos[LEFT] = min(pos[LEFT], j);
            pos[BOTTOM] = i + 1;
            pos[RIGHT] = max(pos[RIGHT], j + 1);
        }
    }
    
    for(int i = 0; i < 4; i++)
        cout << pos[i] << ' ';
    
    return pos;
}