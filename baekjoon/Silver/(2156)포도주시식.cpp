/**
 * baekjoon - 2156
 * dp
 */

#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int N;
int arr[100001];
int dp[100001];

void Input(){
    fio;
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void Solution(){
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= N; i++){
        dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]});
    }
}

int main(){
    Input();
    Solution();

    cout << dp[N];

    return 0;
}