#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int INF = 1000000;
int t, n, m, k, u, v, c, d, answer = INF;
int dp[101][10001];
vector<pair<int, pair<int, int>>> arr[101];

int dfs(int idx, int totalcost) {
    if (idx == n) {
        return 0;
    }
    if (dp[idx][totalcost] != -1) {
        return dp[idx][totalcost];
    }
    dp[idx][totalcost] = INF;
    int size = arr[idx].size();
    for (int i = 0; i < size; i++) {
        int to = arr[idx][i].first;
        int cost = arr[idx][i].second.first;
        int distance = arr[idx][i].second.second;
        if (totalcost + cost > m) {
            continue;
        }
        dp[idx][totalcost] = min(dp[idx][totalcost], dfs(to, totalcost + cost) + distance);
    }
    return dp[idx][totalcost];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        answer = INF;
        for (int j = 1; j <= n; j++) {
            arr[j].clear();
        }

        for (int j = 0; j < k; j++) {
            cin >> u >> v >> c >> d;
            arr[u].push_back(make_pair(v, make_pair(c, d)));
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        answer = dfs(1, 0);

        if (answer == INF) {
            cout << "Poor KCM";
        } else {
            cout << answer;
        }

        cout << "\n";
    }
    return 0;
}