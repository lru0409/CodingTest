#include <iostream>
#include <queue>
using namespace std;

int L(int origin)
{
    int arr[4] = { 0, };

    for(int i = 3; i >= 0; i--)
    {
        arr[i] = origin % 10;
        origin /= 10;
    }

    int tmp = arr[0];
    for(int i = 0; i < 3; i++)
        arr[i] = arr[i + 1];
    arr[3] = tmp;

    int ret = 0;
    for(int i = 0; i < 4; i++)
        ret = ret * 10 + arr[i];
    
    return (ret);
}

int R(int origin)
{
    int arr[4] = { 0, };

    for(int i = 3; i >= 0; i--)
    {
        arr[i] = origin % 10;
        origin /= 10;
    }

    int tmp = arr[3];
    for(int i = 3; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = tmp;

    int ret = 0;
    for(int i = 0; i < 4; i++)
        ret = ret * 10 + arr[i];
    
    return (ret);
}

void BFS(int A, int B)
{
    queue<pair<int, string> > Q;
    bool visited[10000] = { false, };
    Q.push(make_pair(A, ""));
    visited[A] = true;

    while (!Q.empty())
    {
        int num = Q.front().first;
        string cmd = Q.front().second;
        Q.pop();

        if (num == B)
        {
            cout << cmd << '\n';
            return;
        }

        int d = (num * 2) % 10000;
        if (!visited[d])
        {
            visited[d] = true;
            Q.push(make_pair(d, cmd + 'D'));
        }

        int s = num - 1;
        if (s < 0) s = 9999;
        if (!visited[s])
        {
            visited[s] = true;
            Q.push(make_pair(s, cmd + 'S'));
        }

        int l = L(num);
        if (!visited[l])
        {
            visited[l] = true;
            Q.push(make_pair(l, cmd + 'L'));
        }

        int r = R(num);
        if (!visited[r])
        {
            visited[r] = true;
            Q.push(make_pair(r, cmd + 'R'));
        }
    }
}

int main()
{
    int T, A, B;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> A >> B;
        BFS(A, B);
    }

    return (0);
}