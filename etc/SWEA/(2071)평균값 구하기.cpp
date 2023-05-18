/**
 * SW Expert Academy - 2071
 * math
 */

#include <iostream>
#include <cmath>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int sum = 0;
        int num;
        for (int i = 0; i < 10; i++)
        {
            cin >> num;
            sum += num;
        }

        cout << "#" << t << " " << round((float)sum / (float)10) << endl;
    }

    return 0;
}