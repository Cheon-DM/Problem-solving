/**
 * baekjoon - 4949
 * string, stack
 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    while (1)
    {
        string sentense;
        getline(cin, sentense);

        if (sentense == ".")
            break;

        stack<char> s;
        bool flag = false;
        for (int i = 0; i < sentense.size(); i++)
        {
            if (sentense[i] == '(' || sentense[i] == '[')
            {
                s.push(sentense[i]);
            }

            else if (sentense[i] == ')')
            {
                if (!s.empty())
                {
                    int top = s.top();

                    if (top == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }

            else if (sentense[i] == ']')
            {
                if (!s.empty())
                {
                    int top = s.top();

                    if (top == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }

        if (!s.empty())
            flag = true;

        if (flag)
            cout << "no\n";
        else
            cout << "yes\n";
    }

    return 0;
}