/**
 * baekjoon - 11650
 * sorting
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> spot;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        spot.push_back({x, y});
    }

    sort(spot.begin(), spot.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << spot[i].first << " " << spot[i].second << "\n";
    }

    return 0;
}