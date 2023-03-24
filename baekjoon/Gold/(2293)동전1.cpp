#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main(){
    fio;
    int n, k; cin >> n >> k;

    vector<int> ary(n);
    vector<int> dp(k+1);

    dp[0] = 1;
    for (int i = 0; i < n; i++){
        cin >> ary[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = ary[i]; j <= k; j++){
            dp[j] += dp[j - ary[i]];
        }
    }

    cout << dp[k];
}

/*
10원을 1,2,5원으로 모든 경우의 수
    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10
1원 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1  -> dp[1]부터 dp[i] += dp[i-1]
2원 1 | 1 | 2 | 2 | 3 | 3 | 4 | 4 | 5 | 5 | 6  -> dp[2]부터 dp[i] += dp[i-2]
5원 1 | 1 | 2 | 2 | 3 | 4 | 6 | 6 | 8 | 8 | 10 -> dp[5]부터 dp[i] += dp[i-5]
*/