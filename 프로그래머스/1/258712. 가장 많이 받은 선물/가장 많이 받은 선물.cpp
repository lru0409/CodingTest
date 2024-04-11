#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, int> gift_index; // 선물 지수
unordered_map<string, unordered_map<string, int>> give_count; // 각 친구에게 선물 준 횟수
unordered_map<string, int> receive_count; // 다음 달에 선물 받는 횟수

vector<string> tmp;

void Recursive(vector<string>& friends, int next)
{
    if (tmp.size() == 2)
    {
        if (give_count[tmp[0]][tmp[1]] < give_count[tmp[1]][tmp[0]])
            receive_count[tmp[1]] += 1;
        else if (give_count[tmp[0]][tmp[1]] > give_count[tmp[1]][tmp[0]])
            receive_count[tmp[0]] += 1;
        else
        {
            if (gift_index[tmp[0]] < gift_index[tmp[1]])
                receive_count[tmp[1]] += 1;
            else if (gift_index[tmp[0]] > gift_index[tmp[1]])
                receive_count[tmp[0]] += 1;
        }
        return;
    }
    
    for(int i = next; i < friends.size(); i++)
    {
        tmp.push_back(friends[i]);
        Recursive(friends, i + 1);
        tmp.pop_back();
    }
}

int solution(vector<string> friends, vector<string> gifts)
{  
    for(int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string given, received;
        ss >> given >> received;
        
        gift_index[given] += 1;
        gift_index[received] -= 1;
        give_count[given][received] += 1;
    }
    
    Recursive(friends, 0);
    
    unordered_map<string, int>::iterator it;
    int answer = 0;
    for(it = receive_count.begin(); it != receive_count.end(); it++)
    {
        if (answer < it->second)
            answer = it->second;
    }
    
    return answer;
}