/**
 * baekjoon - 7662
 * multiset
 */

#include <iostream>
#include <set>
using namespace std;

char cmd;
int T, k, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> T;
    while (T--)
    {
        cin >> k;
        multiset<int> ms; // 오름차순 정렬

        for (int i = 0; i < k; i++)
        {
            cin >> cmd >> n;

            if (cmd == 'I')
            {
                ms.insert(n);
            }

            else
            {
                if (ms.empty())
                    continue;

                else if (n == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter); // 최댓값 삭제
                }

                else
                {
                    ms.erase(ms.begin()); // 최솟값 삭제
                }
            }
        }

        if (ms.empty())
        {
            cout << "EMPTY\n";
        }

        else
        {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << '\n';
        }
    }

    return 0;
}