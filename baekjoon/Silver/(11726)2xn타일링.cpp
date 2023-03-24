/**
 * baekjoon - 11726
 * dp
 */

#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int N;
int dp[1001];

void Input(){
    fio;
    cin >> N;
}

void Dp(int n){
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }
}

void Solution(){
    Dp(N);
}

int main(){
    Input();
    Solution();

    cout << dp[N];

    return 0;
}