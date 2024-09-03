#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Y 0
#define X 1

#define SY 0
#define SX 1
#define EY 2
#define EX 3

const int DY[4] = {-1, 1, 0, 0};
const int DX[4] = {0, 0, -1, 1};

// map 상에서 시작점에서 가장 가까운 고객 배열과 거리 구하기
pair<vector<int>, int> BFS1(int startPos[], vector< vector<int> >& map, int N)
{
    queue<pair<pair<int, int>, int>> Q; // y, x, count
    vector< vector<bool> > visited(N, vector<bool>(N, false));
    vector<int> minCustomers;

    Q.push(make_pair(make_pair(startPos[Y], startPos[X]), 0));
    int minCount = 400;

    while (!Q.empty())
    {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int count = Q.front().second;
        Q.pop();

        if (map[y][x] >= 2) {
            if (count < minCount) {
                minCount = count;
                minCustomers.clear();
            }
            if (count == minCount)
                minCustomers.push_back(map[y][x]);
            continue;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int ny = y + DY[i];
            int nx = x + DX[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx] || map[ny][nx] == 1) continue;
            visited[ny][nx] = true;
            Q.push(make_pair(make_pair(ny, nx), count + 1));
        }
    }

    return {minCustomers, minCount};
}

// 특정 고객의 시작점에서 목적지까지 거리 구하기
int BFS2(vector<int>& customer, vector< vector<int> >& map, int N)
{
    queue<pair<pair<int, int>, int>> Q; // y, x, count
    vector< vector<bool> > visited(N, vector<bool>(N, false));
    Q.push({{customer[SY], customer[SX]}, 0});

    while (!Q.empty())
    {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int count = Q.front().second;
        Q.pop();

        if (y == customer[EY] && x == customer[EX])
            return (count);
        for (int i = 0; i < 4; i++)
        {
            int ny = y + DY[i];
            int nx = x + DX[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx] || map[ny][nx] == 1) continue;
            visited[ny][nx] = true;
            Q.push(make_pair(make_pair(ny, nx), count + 1));
        }
    }

    return (-1);
}

int main()
{
    int N, M, fuel;
    cin >> N >> M >> fuel;
    vector< vector<int> > map(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    int taxiPos[2];
    cin >> taxiPos[Y] >> taxiPos[X];
    taxiPos[Y] -= 1;
    taxiPos[X] -= 1;
    vector< vector<int> > customers(M, vector<int>(4));
    for (int i = 0; i < M; i++)
    {
        cin >> customers[i][SY] >> customers[i][SX] >> customers[i][EY] >> customers[i][EX];
        for (int j = 0; j < 4; j++) customers[i][j]--;
    }
    for (int i = 0; i < M; i++)
        map[customers[i][SY]][customers[i][SX]] = i + 2;

    while (M--)
    {
        // 가장 가까운 위치의 승객 찾기
        pair<vector<int>, int> data = BFS1(taxiPos, map, N);
        vector<int> minCustomers = data.first;
        int dist = data.second;
        if (minCustomers.size() == 0) {
            cout << "-1\n";
            return 0;
        }
        vector<int> selectedCustomer;
        for (int i = 0; i < minCustomers.size(); i++)
        {
            vector<int> customer = customers[minCustomers[i] - 2];
            if (selectedCustomer.size() == 0 ||
                customer[SY] < selectedCustomer[SY] || 
                (customer[SY] == selectedCustomer[SY] && customer[SX] < selectedCustomer[SX]))
                selectedCustomer = customer;
        }

        // 승객 위치로 이동
        if (fuel <= dist) {
            cout << "-1\n";
            return 0;
        }
        fuel -= dist;
        map[selectedCustomer[SY]][selectedCustomer[SX]] = 0;

        // 승객의 목적지로 이동
        int toDestDist = BFS2(selectedCustomer, map, N);
        if (fuel < toDestDist || toDestDist == -1) {
            cout << "-1\n";
            return 0;
        }
        fuel += toDestDist;
        taxiPos[Y] = selectedCustomer[EY];
        taxiPos[X] = selectedCustomer[EX];
    }

    cout << fuel << "\n";
    return 0;
}