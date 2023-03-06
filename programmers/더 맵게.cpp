/**
 * programmers - 더 맵게
 * heap
 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    // 스코빌 지수 minheap에 담기
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    bool flag = false;

    while (pq.top() < K)
    {
        if (pq.size() == 1)
        {
            flag = true;
            break;
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int res = first + (2 * second);
        pq.push(res);
        answer++;
    }

    if (flag)
        return -1;

    return answer;
}