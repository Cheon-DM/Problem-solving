/**
 * programmers - 모의고사
 * brute force
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int way1[] = {1, 2, 3, 4, 5};
int way2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int way3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<int> ans)
{
    vector<int> person;
    vector<pair<int, int>> result;

    int p1 = 0, p2 = 0;
    int cnt1 = 0;
    // way1
    while (p2 != ans.size())
    {
        if (way1[p1++] == ans[p2++])
        {
            cnt1++;
        }

        if (p1 >= (sizeof(way1) / sizeof(int)))
        {
            p1 = 0;
        }
    }
    result.push_back({1, cnt1});

    // way2
    p1 = 0, p2 = 0;
    int cnt2 = 0;
    while (p2 != ans.size())
    {
        if (way2[p1++] == ans[p2++])
        {
            cnt2++;
        }

        if (p1 >= (sizeof(way2) / sizeof(int)))
        {
            p1 = 0;
        }
    }
    result.push_back({2, cnt2});

    // way3
    p1 = 0, p2 = 0;
    int cnt3 = 0;
    while (p2 != ans.size())
    {
        if (way3[p1++] == ans[p2++])
        {
            cnt3++;
        }

        if (p1 >= (sizeof(way3) / sizeof(int)))
        {
            p1 = 0;
        }
    }
    result.push_back({3, cnt3});

    sort(result.begin(), result.end(), cmp);

    person.push_back(result[0].first);

    if (result[0].second == result[1].second)
    {
        person.push_back(result[1].first);

        if (result[1].second == result[2].second)
        {
            person.push_back(result[2].first);
        }
    }

    return person;
}