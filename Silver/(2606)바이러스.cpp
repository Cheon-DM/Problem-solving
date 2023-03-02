/**
 * baekjoon -
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> links;
vector<bool> visited;

int a = 0;
void dfs(int start)
{
    a++;
    visited[start] = true;

    for (int i = 0; i < links[start].size(); i++)
    {
        int next = links[start][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int bfs()
{
    int ans = 0;
    queue<int> q;

    // 초기 설정
    visited[1] = true;
    for (int i = 0; i < links[1].size(); i++)
    {
        q.push(links[1][i]);
        visited[links[1][i]] = true;
    }

    while (!q.empty())
    {
        // 큐에서 꺼냄
        int cur = q.front();
        q.pop();
        ans++;

        // 목적지인가 (여기선 생략)

        // 연결된 곳 순회
        for (int i = 0; i < links[cur].size(); i++)
        {
            int next = links[cur][i];

            // 갈 수 있는가?
            if (!visited[next])
            {
                // 체크인
                visited[next] = true;

                // 큐에 넣음
                q.push(next);
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    cin >> M;

    links.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    int ans = bfs();
    visited.assign(N + 1, false);
    dfs(1);
    cout << ans << endl;
    cout << a << endl;

    return 0;
}