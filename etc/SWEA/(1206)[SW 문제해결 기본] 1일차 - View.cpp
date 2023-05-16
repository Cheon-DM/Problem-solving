/**
 * SW Expert Academy - 1206
 * compare
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T = 10;
vector<int> buildings;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;

        buildings.clear();

        for (int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            buildings.push_back(n);
        }

        int result = 0;

        for (int i = 2; i < N - 2; i++)
        {
            if (buildings[i] > buildings[i - 2] &&
                buildings[i] > buildings[i - 1] &&
                buildings[i] > buildings[i + 1] &&
                buildings[i] > buildings[i + 2])
            {
                int m = max(buildings[i - 2], buildings[i - 1]);
                m = max(m, buildings[i + 1]);
                m = max(m, buildings[i + 2]);
                result += (buildings[i] - m);
            }
        }

        cout << "#" << t << " " << result << endl;
    }

    return 0;
}