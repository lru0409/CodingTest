#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    stack<int> stack;
    vector<int> answer(prices.size());

    for(int i = 0; i < prices.size(); i++)
    {
        // 현재 가격이 떨어진 과거의 시점 찾기
        while(!stack.empty() &&
                prices[stack.top()] > prices[i])
        {
            // 가격이 떨어지지 않은 기간이 확정된 시점
            answer[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    
    while(!stack.empty())
    {
        answer[stack.top()] = prices.size() - stack.top() - 1;
        stack.pop();
    }
    
    return answer;
}