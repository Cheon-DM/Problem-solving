/**
 * baekjoon - 1654
 * binary search
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
int LAN[10000];
int unit = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> LAN[i];
    }

    for (int i = 0; i < K; i++)
    {
        unit = max(unit, LAN[i]);
    }

    long long left = 1, right = unit;
    int answer;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < K; i++)
        {
            cnt += (LAN[i] / mid);
        }

        if (cnt >= N)
        {
            answer = mid;
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}