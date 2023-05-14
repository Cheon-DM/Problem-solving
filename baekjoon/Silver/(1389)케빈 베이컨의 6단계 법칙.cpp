/**
 * baekjoon - 1389
 * graph, bfs, floyd-warshall
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, A, B;
vector<int> links[101];
int kevinBacon[101][101] = {
    0,
};

void bfs(int start)
{
    bool visited[101] = {
        false,
    };
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        int c = q.front().first;
        int s = q.front().second;
        q.pop();

        kevinBacon[start][c] = s;

        for (int i = 0; i < links[c].size(); i++)
        {
            int n = links[c][i];

            if (!visited[n])
            {
                visited[n] = true;
                q.push({n, s + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        links[A].push_back(B);
        links[B].push_back(A);
    }

    int result = 5000;
    int p = -1;
    for (int i = 1; i <= N; i++)
    {
        bfs(i);

        int s = 0;
        for (int j = 1; j <= N; j++)
        {
            s += kevinBacon[i][j];
        }

        if (result > s)
        {
            p = i;
            result = s;
        }
    }

    cout << p << '\n';

    return 0;
}