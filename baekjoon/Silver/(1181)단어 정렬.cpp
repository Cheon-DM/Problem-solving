/**
 * baekjoon - 1181
 * string, sorting
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;

bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    // 중복 제거
    set<string> s;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(str);
    }

    // vector로 옮기고 정렬
    vector<string> v;
    for (auto str : s)
    {
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto str : v)
    {
        cout << str << endl;
    }

    return 0;
}