/**
 * baekjoon - 10814
 * sorting
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, pair<int, string>>> v;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
    if (a.second.first == b.second.first)
    {
        return a.first < b.first;
    }
    return a.second.first < b.second.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    int age;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;
        v.push_back({i, {age, name}});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].second.first << " " << v[i].second.second << '\n';
    }

    return 0;
}