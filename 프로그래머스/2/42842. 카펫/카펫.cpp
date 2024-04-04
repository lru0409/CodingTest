#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int yh; // 노란 부분의 높이
    for(yh = 1; yh * yh <= yellow; yh++)
    {
        if (yellow % yh != 0)
            continue;
        if ((yh * 2) + (yellow / yh * 2) + 4 == brown)
            break;
    }
    
    vector<int> answer;
    answer.push_back((yellow / yh) + 2);
    answer.push_back(yh + 2);
    return answer;
}
