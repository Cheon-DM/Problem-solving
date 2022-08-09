#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;

    // input
    int n; cin >> n;
    int square[n+1][n+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> square[i][j];
        }
    }

    // solution
    int dp[n+1][n+1] = {0, };
    int _max;
    dp[1][1] = square[1][1];
    _max = dp[1][1];
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + square[i][j];
            if (_max < dp[i][j]) _max = dp[i][j];
        }
    }

    cout << _max;

}

// dp