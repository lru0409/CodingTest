#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            if (j-1 < 0)
                triangle[i][j] += triangle[i-1][j];
            else if (j == triangle[i-1].size())
                triangle[i][j] += triangle[i-1][j-1];
            else
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    
    int answer = 0;
    for(int i = 0; i < triangle.back().size(); i++)
        if (answer < triangle.back()[i])
            answer = triangle.back()[i];
    return answer;
}