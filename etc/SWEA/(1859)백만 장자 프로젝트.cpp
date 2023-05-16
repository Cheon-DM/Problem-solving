/**
 * SW Expert Academy - 1859
 * comparing
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int T, N;
vector<int> nums;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        nums.clear();

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        long long result = 0;
        int max = nums[N - 1];

        for (int i = N - 2; i >= 0; i--)
        {
            if (max < nums[i])
            {
                max = nums[i];
            }

            else
            {
                result += (max - nums[i]);
            }
        }

        cout << "#" << t << " " << result << endl;
    }

    return 0;
}