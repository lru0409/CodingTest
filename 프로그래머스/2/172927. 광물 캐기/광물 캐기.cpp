#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

#define DIA 0
#define IRON 1
#define STONE 2

bool comp(vector<int> v1, vector<int> v2)
{
    if (v1[DIA] != v2[DIA])
        return v1[DIA] > v2[DIA];
    if (v1[IRON] != v2[IRON])
        return v1[IRON] > v2[IRON];
    return v1[STONE] > v2[STONE];
}

int solution(vector<int> picks, vector<string> minerals) {
    vector<vector<int> > parsed;
    
    int total_picks = 0;
    for(int i = 0; i <= 2; i++)
        total_picks += picks[i];

    for(int i = 0; i < minerals.size(); i++)
    {
        if (i == total_picks * 5)
            break;
        if (i % 5 == 0) {
            vector<int> vec(3);
            parsed.push_back(vec);
        }
        if (minerals[i] == "diamond") parsed.back()[DIA] += 1;
        else if (minerals[i] == "iron") parsed.back()[IRON] += 1;
        else if (minerals[i] == "stone") parsed.back()[STONE] += 1;
    }
    
    sort(parsed.begin(), parsed.end(), comp);
    
    int answer = 0; // 최소한의 피로도
    int picks_idx = 0, parsed_idx = 0;
    while (parsed_idx < parsed.size())
    {
        while (picks_idx <= 2 && picks[picks_idx] == 0)
            picks_idx++;
        
        // stone 캐기
        answer += parsed[parsed_idx][STONE];
        
        // iron 캐기
        if (picks_idx == STONE) answer += 5 * parsed[parsed_idx][IRON];
        else answer += parsed[parsed_idx][IRON];

        // diamond 캐기
        if (picks_idx == STONE) answer += 25 * parsed[parsed_idx][DIA];
        else if (picks_idx == IRON) answer += 5 * parsed[parsed_idx][DIA];
        else answer += parsed[parsed_idx][DIA];
        
        picks[picks_idx]--;
        parsed_idx++;
    }
    
    return answer;
}
