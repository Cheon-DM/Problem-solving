/**
 * SW Expert Academy - 2072
 * math
 */

#include <iostream>
#include <vector>
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
        int n;
        int result = 0;
        for (int i = 0; i < 10; i++)
        {
            cin >> n;

            if (n % 2 == 1)
            {
                result += n;
            }
        }

        cout << "#" << t << " " << result << endl;
    }

    return 0;
}