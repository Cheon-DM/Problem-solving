/**
 * baekjoon - 10250
 * implementation, math
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, H, W, N;

bool cmp(int a, int b)
{
    int a_100 = a / 100;
    int b_100 = b / 100;

    if (a % 100 == b % 100)
    {
        return a_100 < b_100;
    }
    return a % 100 < b % 100;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> T;
    while (T--)
    {
        cin >> H >> W >> N;
        vector<int> v;

        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                v.push_back(i * 100 + j);
            }
        }

        sort(v.begin(), v.end(), cmp);

        cout << v[N - 1] << '\n';
    }

    return 0;
}