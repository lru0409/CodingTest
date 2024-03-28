#include <string>
#include <vector>

#include <iostream>

using namespace std;

// 자물쇠 확장
vector<vector<int>> *expandLock(vector<vector<int>>& lock)
{
    vector<vector<int>> *new_lock = 
        new vector<vector<int>>(lock.size() * 3 - 2, vector<int>(lock.size() * 3 - 2, 0));
    
    for(int x = 0; x < lock.size(); x++)
        for(int y = 0; y < lock.size(); y++)
            (*new_lock)[x+lock.size()-1][y+lock.size()-1] = lock[x][y];
        
    return new_lock;
}

// 열쇠를 시계 방향으로 90도 회전
void rotateLock(vector<vector<int>>& key)
{
    int temp[20][20];
    
    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j < key.size(); j++)
            temp[j][key.size()-i-1] = key[i][j];

    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j < key.size(); j++)
            key[i][j] = temp[i][j];
}

bool check(vector<vector<int>>& key, int n, vector<vector<int>> lock)
{
    for(int x = 0; x < n * 2 - 1; x++) // 0 1 2 3 4
    {
        for(int y = 0; y < n * 2 - 1; y++) // 0 1 2 3 4
        {
            vector<vector<int>> temp = lock;
            for(int i = 0; i < key.size(); i++) // 0 1 2
                for(int j = 0; j < key[i].size(); j++) // 0 1 2
                    temp[x+i][y+j] += key[i][j];
            
            bool isOpen = true;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if (temp[i+n-1][j+n-1] != 1)
                        isOpen = false;
            if (isOpen)
                return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    vector<vector<int>> *new_lock = expandLock(lock);
    for(int i = 0; i < 4; i++) // 네 방향 회전
    {
        if (check(key, lock.size(), *new_lock)) // 현재 열쇠 방향으로 열 수 있는지 확인
            return true;
        rotateLock(key); // 키 회전
    }
    delete new_lock;
    return false;
}