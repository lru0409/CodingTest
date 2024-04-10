#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for(int i = 0; i < prices.size() - 1; i++)
    {
        int j = i + 1;
        while(prices[i] <= prices[j])
        {
            if (j == prices.size() - 1)
                break;
            j++;   
        }
        answer.push_back(j - i);  
    }
    answer.push_back(0);
    
    return answer;
}