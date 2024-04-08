#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, int> M;
    for(int i = 0; i < clothes.size(); i++)
        M[clothes[i][1]] += 1;

    int answer = 1;
    map<string, int>::iterator it;
    for(it = M.begin(); it != M.end(); it++)
        answer *= it->second + 1;   
    answer -= 1;
    
    return answer;
}