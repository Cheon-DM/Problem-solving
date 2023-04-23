/**
 * baekjoon - 7568
 * brute force
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    int w, h;
    for (int i = 0; i < N; i++)
    {
        cin >> w >> h;
        p.push_back({w, h});
    }

    for (int i = 0; i < p.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[i].first < p[j].first && p[i].second < p[j].second)
            {
                cnt++;
            }
        }
        cout << cnt + 1 << '\n';
    }

    return 0;
}