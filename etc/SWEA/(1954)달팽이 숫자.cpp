/**
 * SW Expert Academy - 1954
 * implementation
 */

#include <iostream>
#include <vector>
using namespace std;

int T, N;
int arr[10][10];

void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void write(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                cout << arr[i][j];
            }
            else
            {
                cout << " " << arr[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        init();

        // sol
        int n = 1, i = 0, j = 0;
        arr[i][j] = n;
        n++;

        while (n <= N * N)
        {

            // right
            while (j + 1 < N && arr[i][j + 1] == 0)
            {
                j++;
                arr[i][j] = n++;
            }

            // down
            while (i + 1 < N && arr[i + 1][j] == 0)
            {
                i++;
                arr[i][j] = n++;
            }

            // left
            while (j - 1 >= 0 && arr[i][j - 1] == 0)
            {
                j--;
                arr[i][j] = n++;
            }

            // up
            while (i - 1 >= 0 && arr[i - 1][j] == 0)
            {
                i--;
                arr[i][j] = n++;
            }
        }
        cout << "#" << t << endl;
        write(N);
    }

    return 0;
}