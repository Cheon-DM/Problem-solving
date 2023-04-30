/**
 * baekjoon - 1012
 * bfs, dfs
 */

#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K;
int map[51][51] = {
    0,
};
bool visited[51][51] = {
    false,
};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void init()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void dfs(int cx, int cy)
{

    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;

        if (!visited[nx][ny] && map[nx][ny] == 1)
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> M >> N >> K;

        init();

        for (int k = 0; k < K; k++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        // DFS
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}