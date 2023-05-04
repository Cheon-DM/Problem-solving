/**
 * baekjoon - 11723
 * bitmask
 */

#include <iostream>
#include <vector>
using namespace std;

int M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> M;
    string command;
    int num;
    int s = 0;
    while (M--)
    {
        cin >> command;

        if (command == "add")
        {
            cin >> num;
            s = (s | (1 << --num));
        }

        else if (command == "remove")
        {
            cin >> num;
            s = (s & ~(1 << --num));
        }

        else if (command == "check")
        {
            cin >> num;
            int check = s & (1 << --num);
            cout << (check ? 1 : 0) << '\n';
        }

        else if (command == "toggle")
        {
            cin >> num;
            s = (s ^ (1 << --num));
        }

        else if (command == "all")
        {
            s = (1 << 20) - 1;
        }

        else
        {
            s = 0;
        }
    }

    return 0;
}