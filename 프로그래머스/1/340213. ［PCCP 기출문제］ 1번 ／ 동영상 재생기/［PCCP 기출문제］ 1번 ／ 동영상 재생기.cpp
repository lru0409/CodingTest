#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int getTotalSeconds(string str)
{
    int m, s;
    char colon = ':';

    stringstream ss(str);
    ss >> m >> colon >> s;
    return m * 60 + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int total = getTotalSeconds(video_len);
    int current = getTotalSeconds(pos);
    int op_s = getTotalSeconds(op_start);
    int op_e = getTotalSeconds(op_end);
    
    if (op_s <= current && current <= op_e)
        current = op_e;
    
    int idx = 0;
    while (idx < commands.size())
    {
        if (commands[idx] == "prev")
            current -= min(10, current);
        else if (commands[idx] == "next")
            current += min(10, total - current);
        if (op_s <= current && current <= op_e)
            current = op_e;
        idx++;
    }
    
    string answerM = to_string(current / 60);
    string answerS = to_string(current % 60);
    if (answerM.size() < 2)
        answerM = "0" + answerM;
    if (answerS.size() < 2)
        answerS = "0" + answerS;
    string answer = answerM + ":" + answerS;
    return answer;
}