#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int max_hor = 0;
    int max_ver = 0;
    for(int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);   
        max_hor = max(max_hor, sizes[i][0]);
        max_ver = max(max_ver, sizes[i][1]);
    }

    return max_hor * max_ver;
}