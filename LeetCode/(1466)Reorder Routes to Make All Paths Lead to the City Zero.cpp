/**
 * leetcode - 1466
 * dfs
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int answer = 0;
    bool visited[50001] = {
        false,
    };
    vector<pair<int, int>> links[50001];

    void DFS(int cur)
    {
        for (int i = 0; i < links[cur].size(); i++)
        {
            int next = links[cur][i].first;

            if (!visited[next])
            {
                if (links[cur][i].second == 0)
                {
                    answer++;
                }
                visited[next] = true;
                DFS(next);
                visited[next] = false;
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connect)
    {

        for (int i = 0; i < connect.size(); i++)
        {
            int start = connect[i][0];
            int end = connect[i][1];

            links[start].push_back({end, 0});
            links[end].push_back({start, 1});
        }

        visited[0] = true;
        DFS(0);

        return answer;
    }
};