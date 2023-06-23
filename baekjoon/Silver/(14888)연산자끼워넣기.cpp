/**
 * baekjoon - 14888
 * bruteforce, backtracking
 * */

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int nums[11], Oper[4];
long long MIN = 1000000000, MAX = -1000000000;

void backtracking(int step, long long result, int oper[4]) {
    if (step == N) {
        MIN = min(MIN, result);
        MAX = max(MAX, result);
        return;
    }

    if (oper[0] != 0) {
        long long temp = result;
        temp += nums[step];
        oper[0]--;
        backtracking(step + 1, temp, oper);
        oper[0]++;
    }
    if (oper[1] != 0) {
        long long temp = result;
        temp -= nums[step];
        oper[1]--;
        backtracking(step + 1, temp, oper);
        oper[1]++;
    }
    if (oper[2] != 0) {
        long long temp = result;
        temp *= nums[step];
        oper[2]--;
        backtracking(step + 1, temp, oper);
        oper[2]++;
    }
    if (oper[3] != 0) {
        long long temp = result;
        if (result > 0) {
            temp /= nums[step];
        } else {
            temp = -temp;
            temp /= nums[step];
            temp = -temp;
        }
        oper[3]--;
        backtracking(step + 1, temp, oper);
        oper[3]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> Oper[i];
    }

    backtracking(1, nums[0], Oper);

    cout << MAX << '\n';
    cout << MIN << '\n';

    return 0;
}