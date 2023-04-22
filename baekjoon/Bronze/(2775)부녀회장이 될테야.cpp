/**
 * baekjoon - 2775
 * dp
 */

#include <iostream>
#include <vector>
using namespace std;

int T;
int k, n;
int dp[15][15] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> T;

    // init
    for (int j = 1; j <= 14; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= 14; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    while (T--)
    {
        cin >> k >> n;

        cout << dp[k][n] << "\n";
    }

    return 0;
}