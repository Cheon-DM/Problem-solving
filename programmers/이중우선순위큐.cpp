/**
 * programmers - 이중우선순위큐
 * priority queue
 */

#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int, vector<int>, less<>> maxHeap;

    int cnt = 0;

    for (int i = 0; i < operations.size(); i++)
    {
        istringstream ss(operations[i]);
        string tmp;
        vector<string> command;
        while (getline(ss, tmp, ' '))
        {
            command.push_back(tmp);
        }

        // insert
        if (command[0] == "I")
        {
            cnt++;
            minHeap.push(stoi(command[1]));
            maxHeap.push(stoi(command[1]));
        }

        // pop
        else
        {
            if (maxHeap.empty() || minHeap.empty())
                continue;

            if (command[1] == "1")
            {
                maxHeap.pop();
                cnt--;
            }
            else
            {
                minHeap.pop();
                cnt--;
            }

            if (cnt == 0)
            {
                while (!maxHeap.empty())
                {
                    maxHeap.pop();
                }
                while (!minHeap.empty())
                {
                    minHeap.pop();
                }
            }
        }
    }

    if (minHeap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    else
    {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    return answer;
}