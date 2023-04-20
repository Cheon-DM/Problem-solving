/**
 * baekjoon - 10866
 * deque
 */

#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    string command;
    int num;
    while (N--)
    {
        cin >> command;

        if (command == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }

        else if (command == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }

        else if (command == "pop_front")
        {
            if (!dq.empty())
            {
                int frt = dq.front();
                dq.pop_front();
                cout << frt << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }

        else if (command == "pop_back")
        {
            if (!dq.empty())
            {
                int back = dq.back();
                dq.pop_back();
                cout << back << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }

        else if (command == "size")
        {
            cout << dq.size() << '\n';
        }

        else if (command == "empty")
        {
            if (!dq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << 1 << '\n';
            }
        }

        else if (command == "front")
        {
            if (!dq.empty())
            {
                int frt = dq.front();
                cout << frt << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }

        else
        {
            if (!dq.empty())
            {
                int back = dq.back();
                cout << back << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}