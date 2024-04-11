#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts)
{
    unordered_map<string, int> gift_index; // 선물 지수
    unordered_map<string, unordered_map<string, int>> give_count; // 각 친구에게 선물 준 횟수
    unordered_map<string, int> receive_count; // 다음 달에 선물 받는 횟수

    // 각 친구의 선물 지수, 다른 친구에게 선물 준 횟수 저장하기
    for(int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string given, received;
        ss >> given >> received;
        
        gift_index[given] += 1;
        gift_index[received] -= 1;
        give_count[given][received] += 1;
    }
    
    // 모든 친구들의 조합에 대해서 누가 선물을 받는지 구하기
    for(int i = 0; i < friends.size(); i++)
    {
        for(int j = i + 1; j < friends.size(); j++)
        {
            string f1 = friends[i], f2 = friends[j];
            if (give_count[f1][f2] < give_count[f2][f1])
                receive_count[f2] += 1;
            else if (give_count[f1][f2] > give_count[f2][f1])
                receive_count[f1] += 1;
            else if (gift_index[f1] < gift_index[f2])
                receive_count[f2] += 1;
            else if (gift_index[f1] > gift_index[f2])
                receive_count[f1] += 1;
        }
    }
    
    // 가장 큰 선물 받은 횟수를 구하기
    unordered_map<string, int>::iterator it;
    int answer = 0;
    for(it = receive_count.begin(); it != receive_count.end(); it++)
    {
        if (answer < it->second)
            answer = it->second;
    }
    
    return answer;
}