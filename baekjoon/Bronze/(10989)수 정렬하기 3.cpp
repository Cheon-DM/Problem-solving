/**
 * baekjoon - 10989
 * sorting
 */

#include <iostream>
using namespace std;

int N;
int count[10001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        count[num]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}