#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

vector<vector<int>> dp(1001, vector<int>(4));
vector<int> R(1001); // 1
vector<int> G(1001); // 2
vector<int> B(1001); // 3

int main(){
    fio;

    int n; cin >> n; // n = 집의 수
    for (int i = 1; i <= n; i++){
        cin >> R[i] >> G[i] >> B[i];
    }

    
    int color;
    dp[1][1] = R[1];
    dp[1][2] = G[1];
    dp[1][3] = B[1];
    for(int i = 2; i <= n; i++){
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + R[i];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + G[i];
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + B[i];
    }

    cout << min({dp[n][1], dp[n][2], dp[n][3]});
    return 0;

}


/* dp
1. i번째 색깔 -> i-1번째 색깔과 겹치지 않음
2. i-1번째 색깔을 제외한 나머지 두가지 색 중 가격 최솟값?
3. 처음 칠해야하는 색 -> 3가지 중 어케 골라?
ex) i-1번째 색이 R일 때:
dp[i] = min(dp[i-1] + G[i], dp[i-1] + B[i])

*/