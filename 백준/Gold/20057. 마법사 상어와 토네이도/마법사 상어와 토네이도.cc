#include <iostream>
#include <vector>
#include <cmath>

#define Y 0
#define X 1

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

int main() {
    std::vector<int> DY = {0, 1, 0, -1};
    std::vector<int> DX = {-1, 0, 1, 0};
    // 왼쪽 방향 기준
    std::vector< std::vector<int> > TORNADO_Y = {
        {0, -1, 1, -1, 1, -2, 2, -1, 1, 0},
        {2, 1, 1, 0, 0, 0, 0, -1, -1, 1},
        {0, -1, 1, -1, 1, -2, 2, -1, 1, 0},
        {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1}
    };
    std::vector< std::vector<int> > TORNADO_X = {
        {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1},
        {0, -1, 1, -1, 1, -2, 2, -1, 1, 0},
        {2, 1, 1, 0, 0, 0, 0, -1, -1, 1},
        {0, 1, -1, 1, -1, 2, -2, 1, -1, 0}
    };
    std::vector<int> PERSENT = {5, 10, 10, 7, 7, 2, 2, 1, 1};

    int N;
    std::cin >> N;
    std::vector< std::vector<int> > A(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    int pos[2] = {N / 2, N / 2};
    int dir = LEFT;
    int moveDist = 1;
    int moveCount = 0;
    int outSendAmount = 0;

    while (pos[Y] != 0 || pos[X] != -1)
    {
        for (int i = 0; i < moveDist; i++) {
            // 이동하기
            pos[Y] += DY[dir];
            pos[X] += DX[dir];
            // 모래 뿌리기
            const int squareSendAmount = A[pos[Y]][pos[X]];
            int aSendAmount = squareSendAmount;
            A[pos[Y]][pos[X]] = 0;
            for (int i = 0; i < 9; i++)
            {
                const int ny = pos[Y] + TORNADO_Y[dir][i];
                const int nx = pos[X] + TORNADO_X[dir][i];
                const int percent = PERSENT[i];
                const int moveSendAmount = floor(squareSendAmount * (percent / 100.0));
                aSendAmount -= moveSendAmount;
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    outSendAmount += moveSendAmount;
                else
                    A[ny][nx] += moveSendAmount;
            }
            // a의 양 더하기
            const int ay = pos[Y] + TORNADO_Y[dir][9];
            const int ax = pos[X] + TORNADO_X[dir][9];
            if (ay < 0 || ax < 0 || ay >= N || ax >= N)
                outSendAmount += aSendAmount;
            else
                A[ay][ax] += aSendAmount;
        }
        moveCount++;
        if (moveCount == 2) {
            moveCount = 0;
            moveDist++;
        }
        dir = (dir + 1) % 4;
    }

    std::cout << outSendAmount << "\n";

    return 0;
}