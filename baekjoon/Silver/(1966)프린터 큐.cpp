/**
 * baekjoon - 1966
 * implementation, simulation, queue
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int T, N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;

        int n;
        queue<pair<int, int>> q;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            q.push({i, n});
            v.push_back(n);
        }

        sort(v.begin(), v.end(), greater<>());
        int MAX = v[0];
        int answer = 0;

        while (!q.empty())
        {
            int num = q.front().first;
            int cost = q.front().second;
            q.pop();

            if (num == M && cost == MAX)
            {
                answer++;
                break;
            }

            if (cost == MAX)
            {
                answer++;
                MAX = v[answer];
            }
            else
            {
                q.push({num, cost});
            }
        }

        cout << answer << "\n";
    }

    return 0;
}