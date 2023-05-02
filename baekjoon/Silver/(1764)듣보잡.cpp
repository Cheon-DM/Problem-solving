/**
 * baekjoon - 1764
 * hashmap
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> M;

    unordered_map<string, int> um;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        um[name]++;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> name;
        um[name]++;
    }

    vector<string> result;
    for (auto a : um)
    {
        if (a.second == 2)
        {
            result.push_back(a.first);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}