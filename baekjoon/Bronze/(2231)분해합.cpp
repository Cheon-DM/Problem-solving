/**
 * baekjoon - 2231
 * brute force
 */

#include <iostream>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    bool flag = false;
    for (int i = 1; i <= 1000000; i++)
    {
        int tmp = i;
        int sum = i;
        while (tmp != 0)
        {
            sum += (tmp % 10);
            tmp /= 10;
        }

        if (sum == N)
        {
            cout << i << '\n';
            flag = true;
            break;
        }
    }

    if (!flag)
        cout << 0 << '\n';

    return 0;
}