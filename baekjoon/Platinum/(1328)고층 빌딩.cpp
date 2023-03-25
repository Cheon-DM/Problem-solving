/**
 * baekjoon - 1328
 * math, dp, combination
 */

#include <iostream>
#include <vector>

#define MOD 1000000007
using namespace std;

int N, L, R;
long long dp[101][101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> L >> R;

    // dp[i][j][k] = dp[i-1][j][k-1] + dp[i-1][j-1][k] + dp[i-1][j][k] * (i-2)
    dp[1][1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= R; k++)
            {
                dp[i][j][k] = (dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k] + (long long)(dp[i - 1][j][k] * (i - 2))) % MOD;
            }
        }
    }

    cout << dp[N][L][R] << "\n";

    return 0;
}