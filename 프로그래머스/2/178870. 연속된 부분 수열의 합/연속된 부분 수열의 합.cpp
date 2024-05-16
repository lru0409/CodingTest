#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<pair<int, vector<int> > > partial; // 길이, 시작 인덱스, 끝 인덱스
    
    int start = 0, end = 0, sum = sequence[start];
    while (true)
    {
        if (sum == k) {
            vector<int> indexs = { start, end };
            partial.push_back(make_pair(end-start+1, indexs));
            if (end + 1 == sequence.size())
                break;
            sum -= sequence[start++];
            sum += sequence[++end];
        } else if (sum < k) {
            if (end + 1 == sequence.size())
                break;
            sum += sequence[++end];
        } else if (sum > k) {
            if (start + 1 == sequence.size())
                break;
            sum -= sequence[start++];
        }
    }
    sort(partial.begin(), partial.end());

    return partial[0].second;
}