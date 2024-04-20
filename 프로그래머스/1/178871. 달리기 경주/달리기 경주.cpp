#include <string>
#include <vector>
#include <unordered_map>
// #include <swap>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    unordered_map<string, int> orders;
    for(int i = 0; i < players.size(); i++)
        orders[players[i]] = i;
    
    for(int i = 0; i < callings.size(); i++)
    {
        int order = orders[callings[i]];
        orders[callings[i]] = order - 1;
        orders[players[order-1]] = order; 
        
        swap(players[order], players[order-1]);
    }
    
    return players;
}