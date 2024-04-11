#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#define MAX 50

using namespace std;

int solution(vector<string> friends, vector<string> gifts)
{
    unordered_map<string, int> friends_idx;
    int gift_graph[MAX][MAX] = { 0, }; // 선물을 주고 받은 횟수
    int gift_score[MAX] = { 0, }; // 선물 지수
    int receive_count[MAX] = { 0, }; // 다음 달에 받는 횟수
    
    // 이름마다 인덱스에 바로 접근할 수 있도록 맵핑
    for(int i = 0; i < friends.size(); i++)
        friends_idx[friends[i]] = i;

    // 각 친구의 선물 지수, 다른 친구에게 선물 준 횟수 저장하기
    string given, received;
    for(int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        ss >> given >> received;
        int given_idx = friends_idx[given], received_idx = friends_idx[received];
        
        gift_graph[given_idx][received_idx] += 1;
        gift_score[given_idx] += 1;
        gift_score[received_idx] -= 1;
    }
    
    // 모든 친구들의 조합에 대해서 누가 선물을 받는지 구하기
    for(int f1 = 0; f1 < friends.size(); f1++)
    {
        for(int f2 = f1 + 1; f2 < friends.size(); f2++)
        {
            if (gift_graph[f1][f2] < gift_graph[f2][f1])
                receive_count[f2] += 1;
            else if (gift_graph[f1][f2] > gift_graph[f2][f1])
                receive_count[f1] += 1;
            else if (gift_score[f1] < gift_score[f2])
                receive_count[f2] += 1;
            else if (gift_score[f1] > gift_score[f2])
                receive_count[f1] += 1;
        }
    }
    
    // 가장 많이 선물 받은 횟수 구하기
    int answer = 0;
    for(int i = 0; i < friends.size(); i++)
    {
        if (answer < receive_count[i])
            answer = receive_count[i];
    }
    
    return answer;
}