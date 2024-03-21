#include <string>
#include <vector>
#include <queue>

using namespace std;

// 7 3 9
// 5 10 1 1 20 1
#include <iostream>

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> complete_dates;
    for(int i = 0; i < progresses.size(); i++)
    {
        int date = (100 - progresses[i]) / speeds[i];
        if(date * speeds[i] != 100 - progresses[i])
            date += 1;
        complete_dates.push_back(date);
    }
    
    vector<int> answer;
    int release_date = complete_dates[0];
    int count = 1;
    int idx = 1;
    while(idx < complete_dates.size())
    {
        if(release_date < complete_dates[idx])
        {
            answer.push_back(count);
            release_date = complete_dates[idx];
            count = 0;
        }
        count++;
        idx++;
    }
    answer.push_back(count);
    return answer;
}