/**
 * baekjoon - 1697
 * bfs
 */

#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool checked[100001] = {
    false,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == K)
        {
            cout << time << '\n';
            break;
        }

        // x-1
        if (cur - 1 >= 0 && cur - 1 <= 100000 && !checked[cur - 1])
        {
            q.push({cur - 1, time + 1});
            checked[cur - 1] = true;
        }

        // x+1
        if (cur + 1 >= 0 && cur + 1 <= 100000 && !checked[cur + 1])
        {
            q.push({cur + 1, time + 1});
            checked[cur + 1] = true;
        }

        // 2*x
        if (2 * cur >= 0 && 2 * cur <= 100000 && !checked[2 * cur])
        {
            q.push({2 * cur, time + 1});
            checked[2 * cur] = true;
        }
    }

    return 0;
}