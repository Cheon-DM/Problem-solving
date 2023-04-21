/**
 * baekjoon - 2108
 * math, implementation, sorting
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> v;
unordered_map<int, int> m;
long long total = 0;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
        m[num]++;
        total += num;
    }

    sort(v.begin(), v.end());

    // map -> pair
    vector<pair<int, int>> MapToPair;
    for (auto a : m)
    {
        MapToPair.push_back({a.first, a.second});
    }
    sort(MapToPair.begin(), MapToPair.end(), cmp);

    float avg = (float)total / (float)N;

    // output
    cout << (int)round(avg) << '\n';
    cout << v[N / 2] << '\n';
    if (MapToPair.size() > 1 && MapToPair[0].second == MapToPair[1].second)
    {
        cout << MapToPair[1].first << '\n';
    }
    else
    {
        cout << MapToPair[0].first << '\n';
    }
    cout << v[N - 1] - v[0] << '\n';

    return 0;
}