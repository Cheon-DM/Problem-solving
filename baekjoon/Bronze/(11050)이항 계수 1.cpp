/**
 * baekjoon - 11050
 * math, implementation, combination
 */

#include <iostream>
#include <vector>
using namespace std;

int N, K;

int facto(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> K;

    long long answer = facto(N) / (facto(N - K) * facto(K));

    cout << answer << '\n';

    return 0;
}