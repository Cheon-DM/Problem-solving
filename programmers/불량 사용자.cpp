/**
 * programmers - 불량 사용자
 * dfs
 */

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<int> v[8];
set<vector<int>> s;
bool visited[8] = {
    false,
};
int bSize;
int answer = 0;

void dfs(vector<int> id)
{
    int iSize = id.size();

    if (iSize == bSize)
    {
        sort(id.begin(), id.end());
        s.insert(id);
        return;
    }

    for (int i = 0; i < v[iSize].size(); i++)
    {
        int n = v[iSize][i];

        if (!visited[n])
        {
            visited[n] = true;

            vector<int> tmp = id;
            tmp.push_back(n);

            dfs(tmp);

            visited[n] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    bSize = banned_id.size();

    for (int i = 0; i < banned_id.size(); i++)
    {
        string ban = banned_id[i];

        for (int j = 0; j < user_id.size(); j++)
        {
            string user = user_id[j];

            if (ban.size() == user.size())
            {
                bool flag = false;
                for (int k = 0; k < ban.size(); k++)
                {
                    if (ban[k] == '*')
                        continue;
                    if (ban[k] != user[k])
                    {
                        flag = true;
                    }
                }

                if (!flag)
                {
                    v[i].push_back(j);
                }
            }
        }
    }

    vector<int> tmp;
    dfs(tmp);

    answer = s.size();

    return answer;
}