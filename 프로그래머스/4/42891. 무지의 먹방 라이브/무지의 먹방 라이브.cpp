#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k)
{
    priority_queue<pair<int, int>> PQ;
    for(int i = 0; i < food_times.size(); i++)
        PQ.push(make_pair(-food_times[i], i + 1));
    
    int time = 0;
    while(!PQ.empty())
    {
        int cur_time = -PQ.top().first - time;
        int cur_food = PQ.top().second;
        if (k < cur_time * PQ.size())
            break;
        k -= cur_time * PQ.size();
        time += cur_time;
        PQ.pop();
    }
    if (PQ.empty())
        return -1;
    
    vector<pair<int, int>> foods; // 번호, 남은 시간 
    while(!PQ.empty())
    {
        int cur_time = -PQ.top().first - time;
        int cur_food = PQ.top().second;
        PQ.pop();
        foods.push_back(make_pair(cur_food, cur_time));
    }
    sort(foods.begin(), foods.end()); // 남은 음식들 번호 기준 오름차순 정렬
    return foods[k % foods.size()].first;
}