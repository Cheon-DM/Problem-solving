/**
 * baekjoon - 2618
 * dp
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
int dp[1001][1001];
vector<pair<int, int>> inputs;

int calDist(int c1, int c2)
{
    int xd = abs(inputs[c1].first - inputs[c2].first);
    int yd = abs(inputs[c1].second - inputs[c2].second);
    return xd + yd;
}

int sol(int p1, int p2)
{
    if (dp[p1][p2] != 0)
        return dp[p1][p2];
    if (p1 == W || p2 == W)
        return 0;

    dp[p1][p2] = 0;
    int nCase = max(p1, p2) + 1;
    int dist1, dist2;

    if (p1 == 0 && p2 == 0)
    { // 사건 시작
        dist1 = sol(nCase, p2) + abs(inputs[nCase].first - 1) + abs(inputs[nCase].second - 1);
        dist2 = sol(p1, nCase) + abs(inputs[nCase].first - N) + abs(inputs[nCase].second - N);
    }
    else if (p1 == 0)
    { // 경찰차1이 움직이지 않은 경우
        dist1 = sol(nCase, p2) + abs(inputs[nCase].first - 1) + abs(inputs[nCase].second - 1);
        dist2 = sol(p1, nCase) + calDist(p2, nCase);
    }
    else if (p2 == 0)
    { // 경찰차2가 움직이지 않은 경우
        dist1 = sol(nCase, p2) + calDist(p1, nCase);
        dist2 = sol(p1, nCase) + abs(inputs[nCase].first - N) + abs(inputs[nCase].second - N);
    }
    else
    { // 그 이후의 사건
        dist1 = sol(nCase, p2) + calDist(p1, nCase);
        dist2 = sol(p1, nCase) + calDist(p2, nCase);
    }

    dp[p1][p2] = min(dist1, dist2);
    return dp[p1][p2];
}

void trace(int p1, int p2)
{

    if (p1 == W || p2 == W)
        return;

    dp[p1][p2] = 0;
    int nCase = max(p1, p2) + 1;
    int dist1, dist2;

    if (p1 == 0 && p2 == 0)
    { // 사건 시작
        dist1 = dp[nCase][p2] + abs(inputs[nCase].first - 1) + abs(inputs[nCase].second - 1);
        dist2 = dp[p1][nCase] + abs(inputs[nCase].first - N) + abs(inputs[nCase].second - N);
    }
    else if (p1 == 0)
    { // 경찰차1이 움직이지 않은 경우
        dist1 = dp[nCase][p2] + abs(inputs[nCase].first - 1) + abs(inputs[nCase].second - 1);
        dist2 = dp[p1][nCase] + calDist(p2, nCase);
    }
    else if (p2 == 0)
    { // 경찰차2가 움직이지 않은 경우
        dist1 = dp[nCase][p2] + calDist(p1, nCase);
        dist2 = dp[p1][nCase] + abs(inputs[nCase].first - N) + abs(inputs[nCase].second - N);
    }
    else
    { // 그 이후의 사건
        dist1 = dp[nCase][p2] + calDist(p1, nCase);
        dist2 = dp[p1][nCase] + calDist(p2, nCase);
    }

    if (dist1 < dist2)
    {
        cout << "1\n";
        trace(nCase, p2);
    }

    else
    {
        cout << "2\n";
        trace(p1, nCase);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> W;
    inputs.assign(W + 1, {0, 0});
    for (int i = 1; i <= W; i++)
    {
        cin >> inputs[i].first >> inputs[i].second;
    }

    cout << sol(0, 0) << "\n";
    trace(0, 0);

    return 0;
}