#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string& s1, const string& s2)
{
    if (s1.length() != s2.length())
        return s1.length() < s2.length();
    return s1 < s2;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<string> rwords(words);
    for(int i = 0; i < rwords.size(); i++)
        reverse(rwords[i].begin(), rwords[i].end());
    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);
    
    vector<int> answer;
    vector<string>::iterator lower_it, upper_it;
    for(int i = 0; i < queries.size(); i++)
    {
        bool is_reverse = false;
        if (queries[i][0] == '?') {
            is_reverse = true;
            reverse(queries[i].begin(), queries[i].end());
        }

        string start(queries[i]);
        for(int j = 0; j < start.length(); j++)
            if (start[j] == '?') start[j] = 'a';
        string end(queries[i]);
        for(int j = 0; j < end.length(); j++)
            if (end[j] == '?') end[j] = 'z';

        if (is_reverse) {
            lower_it = lower_bound(rwords.begin(), rwords.end(), start, comp);
            upper_it = upper_bound(rwords.begin(), rwords.end(), end, comp);
        } else {
            lower_it = lower_bound(words.begin(), words.end(), start, comp);
            upper_it = upper_bound(words.begin(), words.end(), end, comp);
        }
        answer.push_back(upper_it - lower_it);
    }
    
    return answer;
}