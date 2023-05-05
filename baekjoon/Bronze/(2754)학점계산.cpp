/**
 * baekjoon - 2754
 * string
 */

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    string score;
    cin >> score;

    if (score == "A+")
    {
        cout << "4.3" << '\n';
    }

    else if (score == "A0")
    {
        cout << "4.0" << '\n';
    }

    else if (score == "A-")
    {
        cout << "3.7" << '\n';
    }

    else if (score == "B+")
    {
        cout << "3.3" << '\n';
    }

    else if (score == "B0")
    {
        cout << "3.0" << '\n';
    }

    else if (score == "B-")
    {
        cout << "2.7" << '\n';
    }

    else if (score == "C+")
    {
        cout << "2.3" << '\n';
    }

    else if (score == "C0")
    {
        cout << "2.0" << '\n';
    }

    else if (score == "C-")
    {
        cout << "1.7" << '\n';
    }

    else if (score == "D+")
    {
        cout << "1.3" << '\n';
    }

    else if (score == "D0")
    {
        cout << "1.0" << '\n';
    }

    else if (score == "D-")
    {
        cout << "0.7" << '\n';
    }

    else
    {
        cout << "0.0" << '\n';
    }

    return 0;
}