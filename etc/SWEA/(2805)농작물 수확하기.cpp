/**
 * SW Expert Academy - 2805
 * string
 */

#include <iostream>
#include <string>
using namespace std;

int T, N;
string arr[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        int profit = 0;
        int c = N / 2;
        int l = 1;
        int n = 0;

        while (1)
        {
            if (n == N)
                break;

            if (n <= c)
            {
                string str = arr[n].substr(c - n, l);
                for (int i = 0; i < str.size(); i++)
                {
                    profit += str[i] - '0';
                }

                if (n < c)
                {
                    l += 2;
                }
            }

            else
            {
                l -= 2;
                string str = arr[n].substr(c - (N - n - 1), l);
                for (int i = 0; i < str.size(); i++)
                {
                    profit += str[i] - '0';
                }
            }

            n++;
        }

        cout << "#" << t << " " << profit << endl;
    }

    return 0;
}