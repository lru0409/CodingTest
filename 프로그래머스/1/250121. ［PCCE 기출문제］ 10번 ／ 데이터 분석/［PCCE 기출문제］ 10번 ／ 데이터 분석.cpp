#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sort_by_index;

int getIndex(string key)
{
    const string keys[4] = { "code", "date", "maximum", "remain" };
    int index;
    for(index = 0; index < 4; index++)
        if (keys[index] == key) break;
    return index;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;
    
    // ext 값이 val_ext 보다 작은 데이터만 뽑기
    int ext_index = getIndex(ext);
    for(int i = 0; i < data.size(); i++)
    {
        if (data[i][ext_index] < val_ext)
            answer.push_back(data[i]);
    }
    
    // sort_by 값을 기준으로 오름차순 정렬하기
    sort_by_index = getIndex(sort_by);
    sort(answer.begin(), answer.end(), [](vector<int> data1, vector<int> data2) {
        return data1[sort_by_index] <= data2[sort_by_index]; 
    });
    
    return answer;
}