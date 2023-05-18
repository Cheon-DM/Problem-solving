/**
 * SW Expert Academy - 1244
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, change, rest;
string num;
vector<string> ans;

bool hasSame(string number)
{
    for (int i = 0; i < number.length() - 1; i++)
    {
        char c = number[i];
        for (int j = i + 1; j < number.length(); j++)
        {
            if (c == number[j])
                return true;
        }
    }

    return false;
}

void dfs(string number, int i, int level)
{
    if (level == change || i == number.length() - 1)
    {
        ans.push_back(number);
        rest = change - level;
        // cout << number << " " << rest << endl;
        return;
    }

    int max = 0;
    vector<int> vIdx; // 최대가 되는 경우 모두 뽑아내기

    for (int j = i + 1; j < number.length(); j++)
    {
        if (number[i] <= number[j])
        {
            if (number[j] > max)
            {
                max = number[j];

                vIdx.clear();
                vIdx.push_back(j);
            }

            else if (number[j] == max)
            {
                vIdx.push_back(j);
            }
        }
    }

    // swap (다음 dfs)
    bool flag = false;
    for (int v = 0; v < vIdx.size(); v++)
    {
        flag = true;
        string str = number;
        char temp;
        temp = str[i];
        str[i] = str[vIdx[v]];
        str[vIdx[v]] = temp;

        // cout << "swap: " << str << endl;

        dfs(str, i + 1, level + 1);
    }

    if (!flag)
    {
        dfs(number, i + 1, level);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ans.clear();
        cin >> num >> change;

        rest = change;

        dfs(num, 0, 0);
        // cout << "rest: " << rest << endl;
        sort(ans.begin(), ans.end(), greater<>());

        if (rest % 2 == 0)
        {
            cout << "#" << t << " " << ans[0] << endl;
        }

        else if (!hasSame(num))
        {
            string tmp = ans[0];
            char c = tmp[ans[0].length() - 2];
            tmp[ans[0].length() - 2] = tmp[ans[0].length() - 1];
            tmp[ans[0].length() - 1] = c;
            cout << "#" << t << " " << tmp << endl;
        }

        else
        {
            cout << "#" << t << " " << ans[0] << endl;
        }
    }

    return 0;
}