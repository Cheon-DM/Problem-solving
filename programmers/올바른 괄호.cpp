/**
 * programmers - 올바른 괄호
 * stack
 */

#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (c == '(')
        {
            s.push(c);
        }

        else
        {
            if (s.empty())
                return false;

            char top = s.top();
            if (top == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (!s.empty())
    {
        answer = false;
    }
    return answer;
}