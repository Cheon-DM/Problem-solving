#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dp[11];

int main(){
    fio;

    // input
    int t; cin >> t;

    // solution
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int j = 4; j < 11; j++){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }

    for (int i = 0; i < t; i++){
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}

// dp