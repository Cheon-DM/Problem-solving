/**
 * SW Expert Academy - 1204
 * array
 */

#include <iostream>
using namespace std;

int T;
int score[101];

void init()
{
    for (int i = 0; i < 101; i++)
    {
        score[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        int testcase;
        cin >> testcase;

        init();

        for (int i = 0; i < 1000; i++)
        {
            int s;
            cin >> s;
            score[s]++;
        }

        int result = 0;
        int max = 0;
        for (int i = 0; i < 101; i++)
        {
            if (max <= score[i])
            {
                max = score[i];
                result = i;
            }
        }

        cout << "#" << testcase << " " << result << endl;
    }

    return 0;
}