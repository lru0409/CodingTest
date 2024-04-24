#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    unordered_map<string, int> yearningPerName;
    for(int i = 0; i < name.size(); i++)
        yearningPerName[name[i]] = yearning[i];
    
    vector<int> answer;
    for(int i = 0; i < photo.size(); i++)
    {
        int score = 0;
        for(int j = 0; j < photo[i].size(); j++)
            score += yearningPerName[photo[i][j]];
        answer.push_back(score);
    }
    
    return answer;
}