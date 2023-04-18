/**
 * baekjoon - 9012
 * stack, string
 */

#include <iostream>
#include <stack>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> T;

    while (T--)
    {
        stack<char> s;
        string VPS;
        cin >> VPS;

        for (int i = 0; i < VPS.size(); i++)
        {
            if (s.empty())
            {
                s.push(VPS[i]);
            }

            else
            {
                char top = s.top();
                if (top == '(' && VPS[i] == ')')
                {
                    s.pop();
                }
                else
                {
                    s.push(VPS[i]);
                }
            }
        }

        if (s.empty())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}