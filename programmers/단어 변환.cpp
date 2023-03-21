/**
 * programmers - 단어 변환
 * bfs
 */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    int wSize = begin.size();

    bool flag = false;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
        {
            flag = true;
        }
    }

    // words에 target이 존재하지 않으면 변환 X
    if (!flag)
        return 0;

    // bfs
    // init
    queue<pair<string, int>> q;
    bool visited[50] = {
        false,
    };
    q.push({begin, 0});

    while (!q.empty())
    {
        // 큐에서 빼기
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 목적지인가?
        if (cur == target)
        {
            answer = cnt;
            break; // 최소의 경우이므로 target에 도착하면 바로 빠져나와도 됨
        }

        // 순환
        for (int i = 0; i < words.size(); i++)
        {
            // 거치지 않은 곳만 순환
            if (!visited[i])
            {
                int diffCnt = 0; // 현재 단어와 바꿀 단어의 글자 차이 카운트
                for (int j = 0; j < wSize; j++)
                {
                    if (cur[j] != words[i][j])
                    {
                        diffCnt++;
                    }
                }

                if (diffCnt == 1) // 글자 차이 수 = 1이면 다음 단계로 넘어갈 수 있음
                {
                    q.push({words[i], cnt + 1});
                    visited[i] = true;
                }
            }
        }
    }

    return answer;
}