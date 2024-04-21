#include <string>
#include <vector>
#include <stack>

using namespace std;

void GetUV(const string& str, string& u, string& v)
{
    int idx = 0;
    int open_cnt = 0, close_cnt = 0;
    while(true)
    {
        if (str[idx] == '(') {
            open_cnt += 1;
        } else {
            close_cnt += 1;
        }
        if (open_cnt == close_cnt) break;
        idx++;
    }
    u = str.substr(0, idx + 1);
    v = str.substr(idx + 1, str.size() - idx - 1);   
}

bool IsCorrect(string str)
{
    stack<char> stack;

    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') {
            stack.push(str[i]);
        } else {
            if (stack.empty())
                return false;
            stack.pop();
        }
    }
    
    if (!stack.empty())
        return false;
    return true;
}

string Reverse(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') {
            str[i] = ')';
        } else {
            str[i] = '(';
        }
    }
    return str;
}

string Recursive(string str)
{
    if (str == "")
        return "";
    
    // 균형잡힌 괄호 문자열 u, v 얻기
    string u, v;
    GetUV(str, u, v);
    
    // 재귀 호출을 통해 올바른 괄호 문자열 v 얻기
    string correct_v = Recursive(v);
    
    // u가 올바른 괄호 문자열이라면, correct_v를 이어 붙여 반환
    if (IsCorrect(u))
        return u + correct_v;
    else // 아니라면, "( + corrent_v + ) + 첫 문자와 마지막 문자 제거해 뒤집은 u" 반환
        return "(" + correct_v + ")" + Reverse(u.substr(1, u.size() - 2));
}

string solution(string p)
{
    return Recursive(p);
}