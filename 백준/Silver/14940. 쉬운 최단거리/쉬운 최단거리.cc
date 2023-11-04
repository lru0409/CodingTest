#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int N, M;
int num[1001][1001] = {0};
int visited[1001][1001] = {0};
int targetx, targety;
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {-1, 1, 0, 0};
void bfs(int startx, int starty)
{
    queue<pair<int, int> > q;
    q.push(make_pair(startx, starty));
    visited[startx][starty] = 1;
    while (!q.empty())
    {
        int frontx = q.front().first;
        int fronty = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = frontx + direcx[i];
            int dy = fronty + direcy[i];

            if (dx >= 0 && dx < N && dy >= 0 && dy < M)
            {
                if (visited[dx][dy] == 0 && num[dx][dy] != 0)
                {
                    visited[dx][dy] = visited[frontx][fronty] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a == 2)
            {
                targetx = i;
                targety = j;
            }
            num[i][j] = a;
        }
    }

    bfs(targetx, targety);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (num[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << visited[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}