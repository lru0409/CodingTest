#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{    
    stack<char> stack;
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (stack.empty())
                return false;
            stack.pop();
        }
    }
    if (!stack.empty())
        return false;

    return true;
}