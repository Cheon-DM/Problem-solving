/**
 * baekjoon - 12015
 * binary search
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> LIS;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (LIS.size() == 0)
        {
            LIS.push_back(v[i]);
        }

        else if (LIS[LIS.size() - 1] < v[i])
        {
            LIS.push_back(v[i]);
        }

        else
        {
            int l = 0;
            int r = LIS.size() - 1;
            while (l < r)
            {
                int m = (l + r) / 2;

                if (LIS[m] < v[i])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }

            LIS[l] = v[i];
        }
    }

    cout << LIS.size() << endl;

    return 0;
}