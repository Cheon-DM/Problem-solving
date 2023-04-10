/**
 * programmers - 최댓값과 최솟값
 * sorting, string
 */

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";

    istringstream ss(s);
    string tmp;
    vector<int> v;
    while (getline(ss, tmp, ' '))
    {
        v.push_back(stoi(tmp));
    }

    sort(v.begin(), v.end());

    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);

    return answer;
}