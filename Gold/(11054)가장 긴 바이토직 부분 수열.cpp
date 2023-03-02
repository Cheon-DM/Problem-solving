/**
 * baekjoon - 11054
 * dp
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int dp1[1001];
int dp2[1001];
int ans[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        tmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && dp1[j] > tmp)
            {
                tmp = dp1[j];
            }
        }
        dp1[i] = tmp + 1;
        ans[i] += dp1[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        tmp = 0;
        for (int j = N - 1; j > i; j--)
        {
            if (v[i] > v[j] && dp2[j] > tmp)
            {
                tmp = dp2[j];
            }
        }
        dp2[i] = tmp + 1;
        ans[i] += dp2[i];
    }

    sort(ans, ans + N, greater<>());

    cout << ans[0] - 1 << endl;

    return 0;
}