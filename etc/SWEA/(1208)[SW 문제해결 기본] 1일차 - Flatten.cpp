/**
 * SW Expert Academy - 1208
 * array, two pointer
 */

#include <iostream>
#include <vector>
using namespace std;

int box[101];

void init()
{
    for (int i = 0; i <= 100; i++)
    {
        box[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int t = 1; t <= 10; t++)
    {
        int dump;
        cin >> dump;

        init();

        int h;
        for (int i = 0; i < 100; i++)
        {
            cin >> h;
            box[h]++;
        }

        int p1 = 1, p2 = 100;
        while (1)
        {
            if (box[p1] != 0)
                break;
            else
                p1++;
        }
        while (1)
        {
            if (box[p2] != 0)
                break;
            else
                p2--;
        }

        while (1)
        {
            if (p1 == p2 || dump == 0)
                break;

            if (box[p1] != 0 && box[p2] != 0)
            {
                box[p1]--;
                box[p1 + 1]++;
                box[p2]--;
                box[p2 - 1]++;
                dump--;
            }

            if (box[p1] == 0)
            {
                p1++;
            }

            if (box[p2] == 0)
            {
                p2--;
            }
        }

        cout << "#" << t << " " << (p2 - p1) << endl;
    }

    return 0;
}