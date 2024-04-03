#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> M;
    
    for(int i = 0; i < participant.size(); i++)
        M[participant[i]] += 1;
    
    for(int i = 0; i < completion.size(); i++)
        M[completion[i]] -= 1;
    
    map<string, int>::iterator it;
    for(it = M.begin(); it != M.end(); it++)
        if (it->second == 1) break;
    return it->first;
}