/**
 * baekjoon - 1676
 * math
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

    int five = 0;
    int n = 0;
    while (n <= N)
    {
        int tmp = n;

        while (tmp % 5 == 0 && tmp != 0)
        {
            five++;
            tmp /= 5;
        }

        n++;
    }

    cout << five << '\n';

    return 0;
}