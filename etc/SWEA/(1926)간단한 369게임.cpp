/**
 * SW Expert Academy - 1926
 * string
 */

#include <iostream>
#include <string>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cout << 1;
    int n = 2;
    while (n <= N)
    {
        string s = to_string(n);

        bool flag = false;
        string clap = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '3' || s[i] == '6' || s[i] == '9')
            {
                flag = true;
                clap += "-";
            }
        }

        if (flag)
        {
            cout << " " << clap;
        }
        else
        {
            cout << " " << n;
        }

        n++;
    }

    return 0;
}