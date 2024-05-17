#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define H 0
#define M 1
#define PLAY_TIME 2

int getDiff(int h1, int m1, int h2, int m2) // h1, m1 가 더 일러야 함
{
    if (h1 == h2)
        return m2 - m1;
    return (h2 - h1 - 1) * 60 + (60 - m1) + m2;
}

bool comp(pair<string, vector<int>>& p1, pair<string, vector<int>>& p2)
{
    if (p1.second[H] != p2.second[H])
        return p1.second[H] < p2.second[H];
    return p1.second[M] < p2.second[M];
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<pair<string, vector<int>>> parsed; // 과제 이름, {시, 분, 걸리는 시간}
    for(int i = 0; i < plans.size(); i++)
    {
        int h = stoi(plans[i][1].substr(0, 2));
        int m = stoi(plans[i][1].substr(3, 2));
        vector<int> info = {h, m, stoi(plans[i][2])};
        parsed.push_back(make_pair(plans[i][0], info));
    }
    sort(parsed.begin(), parsed.end(), comp);
    
    stack<pair<int, int> > stack; // parsed 인덱스, 남은 시간
    vector<string> answer;
    for(int i = 0; i < parsed.size() - 1; i++)
    {
        int ch = parsed[i].second[H], cm = parsed[i].second[M];
        int nh = parsed[i+1].second[H], nm = parsed[i+1].second[M];
        int diff = getDiff(ch, cm, nh, nm);
        int play_time = parsed[i].second[PLAY_TIME];
        if (diff < play_time) // 미루기
        {
            stack.push(make_pair(i, play_time - diff));
        }
        else if (play_time <= diff) // 미룬 것들 처리하기
        {
            answer.push_back(parsed[i].first);
            int usable_time = diff - play_time;
            while (usable_time && !stack.empty())
            {
                string subject = parsed[stack.top().first].first;
                int remain = stack.top().second;
                if (remain <= usable_time) {
                    answer.push_back(subject);
                    usable_time -= remain;
                    stack.pop();
                } else {
                    stack.top().second -= usable_time;
                    break;
                }
            }
        }
    }
    answer.push_back(parsed.back().first);
    while (!stack.empty())
    {
        answer.push_back(parsed[stack.top().first].first);
        stack.pop();
    }

    return answer;
}