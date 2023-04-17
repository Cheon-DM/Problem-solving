/**
 * baekjoon - 1987
 * dfs
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char board[20][20];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int answer = 0;

void dfs(int cx, int cy, int level, bool visited[])
{
    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;

        char n = board[nx][ny];
        if (!visited[n - 'A'])
        {
            visited[n - 'A'] = true;
            dfs(nx, ny, level + 1, visited);
            visited[n - 'A'] = false;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (visited[i])
            cnt++;
    }

    answer = max(answer, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    // dfs
    bool visited[26] = {
        false,
    };
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 0, visited);

    cout << answer << "\n";

    return 0;
}