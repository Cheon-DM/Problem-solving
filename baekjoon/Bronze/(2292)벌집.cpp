/**
 * baekjoon - 2292
 * math
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int N;
    cin >> N;

    int num = 1;
    int cnt = 1;
    while (1)
    {
        if (num >= N)
        {
            break;
        }

        num += (6 * cnt);
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}