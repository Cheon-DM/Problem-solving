/**
 * baekjoon - 18870
 * sorting
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> inputs;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N;

    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        inputs.push_back({n, i});
    }

    sort(inputs.begin(), inputs.end());

    vector<int> answer(N);
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            answer[inputs[i].second] = x;
            continue;
        }

        if (inputs[i - 1].first != inputs[i].first)
        {
            answer[inputs[i].second] = ++x;
        }

        else
        {
            answer[inputs[i].second] = x;
        }
    }

    for (auto a : answer)
    {
        cout << a << " ";
    }

    return 0;
}