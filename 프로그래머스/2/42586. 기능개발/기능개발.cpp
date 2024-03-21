#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    int release_day;
    for(int i = 0; i < progresses.size(); i++)
    {
        // i번째 작업을 완료하기 위해 필요한 날짜 수 day 구하기
        int day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            day += 1;
        
        if(i == 0 || release_day < day) // 첫 작업이거나, 배포 날짜까지 완료할 수 없는 작업인 경우
        {
            answer.push_back(1);
            release_day = day;
        }
        else // 배포 날짜까지 완료할 수 있는 작업인 경우
        {
            answer.back() += 1;
        }
    }
    return answer;
}