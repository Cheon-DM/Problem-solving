/**
 * baekjoon - 18111
 * implementation, brute force
 */

#include <iostream>
#include <vector>
using namespace std;

int N, M, B;
int map[501][501] = {
    0,
};
int Time = 987654321;
int height;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    // 땅의 높이가 256보다 작으므로,
    // 모든 경우 다 따져보아도 시간 복잡도가 크지 않음.
    // 블록 제거 : 2초, 블록 건설 : 1초

    for (int h = 256; h >= 0; h--)
    {
        int remove = 0;
        int build = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // 블록 제거
                if (h < map[i][j])
                {
                    remove += (map[i][j] - h);
                }

                // 블록 건설
                else
                {
                    build += (h - map[i][j]);
                }
            }
        }

        if (B + remove >= build)
        {
            int timer = remove * 2 + build;
            if (Time > timer)
            {
                Time = timer;
                height = h;
            }
        }
    }

    cout << Time << " " << height << '\n';

    return 0;
}