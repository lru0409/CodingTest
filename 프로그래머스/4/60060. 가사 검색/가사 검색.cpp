#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define SAME 0
#define BIGGER 1
#define SMALLER 2

int comp(const string& s1, const string& s2)
{
    if (s1 == s2)
        return SAME;
    return s1 < s2 ? SMALLER : BIGGER;
}

// query가 더 작거나 같으면 왼쪽으로 / 크면 오른쪽으로
int lowerBound(const string& query, const vector<string>& words)
{
    int start = 0, end = words.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (comp(query, words[mid]) == BIGGER)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

// query가 더 크거나 같으면 오른쪽으로 / 작으면 왼쪽으로
int upperBound(const string& query, const vector<string>& words)
{
    int start = 0, end = words.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (comp(query, words[mid]) == SMALLER)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    unordered_map<int, vector<string> > forward_words;
    unordered_map<int, vector<string> > reverse_words;

    for(int i = 0; i < words.size(); i++) {
        forward_words[words[i].size()].push_back(words[i]);
        reverse(words[i].begin(), words[i].end());
        reverse_words[words[i].size()].push_back(words[i]);
    }

    unordered_map<int, vector<string> >::iterator it;    
    for(it = forward_words.begin(); it != forward_words.end(); it++)
        sort((it->second).begin(), (it->second).end());
    for(it = reverse_words.begin(); it != reverse_words.end(); it++)
        sort((it->second).begin(), (it->second).end());
    
    vector<int> answer;
    int lower_idx, upper_idx;
    for(int i = 0; i < queries.size(); i++)
    {
        bool is_reverse = false;
        if (queries[i][0] == '?') {
            is_reverse = true;
            reverse(queries[i].begin(), queries[i].end());
        }
        
        string start(queries[i]);
        for(int j = 0; j < start.size(); j++)
            if (start[j] == '?') start[j] = 'a';
        string end(queries[i]);
        for(int j = 0; j < end.size(); j++)
            if (end[j] == '?') end[j] = 'z';
        
        if (is_reverse) {
            lower_idx = lowerBound(start, reverse_words[queries[i].length()]);
            upper_idx = upperBound(end, reverse_words[queries[i].length()]);
        } else {
            lower_idx = lowerBound(start, forward_words[queries[i].length()]);
            upper_idx = upperBound(end, forward_words[queries[i].length()]);
        }
        answer.push_back(upper_idx - lower_idx);
    }
    
    return answer;
}