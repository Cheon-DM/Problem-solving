/**
 * baekjoon - 1780
 * divide&conquer, recursion
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[2187][2187];
int a = 0, b = 0, c = 0;

void sol(int x1, int x2, int y1, int y2) {
    // check
    bool isSame = true;
    int n = arr[x1][y1];
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            if (n != arr[i][j]) {
                isSame = false;
                break;
            }
        }
    }

    // divide
    if (!isSame) {
        // 9등분
        int mx1 = (x1 + x2) / 3;
        int my1 = (y1 + y2) / 3;
    }

    else {
        if (n == -1)
            a++;
        else if (n == 0)
            b++;
        else
            c++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 0; j++) {
            cin >> arr[i][j];
        }
    }

    return 0;
}