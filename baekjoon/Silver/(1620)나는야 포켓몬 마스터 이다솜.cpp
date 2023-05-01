/**
 * baekjoon - 1620
 * hashmap
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> nameToNum;
unordered_map<int, string> numToName;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> M;

    string name;
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        nameToNum[name] = i;
        numToName[i] = name;
    }

    string str;
    for (int i = 0; i < M; i++)
    {
        cin >> str;

        if (str[0] >= 'A' && str[0] <= 'Z')
        {
            cout << nameToNum[str] << '\n';
        }

        else
        {
            int num = stoi(str);
            cout << numToName[num] << '\n';
        }
    }

    return 0;
}