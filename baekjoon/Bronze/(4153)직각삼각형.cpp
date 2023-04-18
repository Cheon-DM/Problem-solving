/**
 * baekjoon - 4153
 * math, geometry, pythagoras
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    while (1)
    {
        cin >> n[0] >> n[1] >> n[2];

        if (n[0] == 0 && n[1] == 0 && n[2] == 0)
            break;

        sort(&n[0], &n[3]);

        if (n[0] * n[0] + n[1] * n[1] == n[2] * n[2])
        {
            cout << "right\n";
        }
        else
        {
            cout << "wrong\n";
        }
    }

    return 0;
}