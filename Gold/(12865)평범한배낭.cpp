#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
vector<pair<int, int>> thing(101);
vector<vector<int>> dp(101, vector<int>(100001)); // 가치 저장

int main(){
    fio;

    int n, k; cin >> n >> k; // n = 물품 개수, k = 버틸수 있는 무게
    for(int i = 1; i <= n; i++){ // first = 무게(w), second = 가치(v)
        cin >> thing[i].first >> thing[i].second;    
    }

    // sort(thing.begin(), thing.end(), compare);

    for (int i = 1; i <= n; i++){ // i번째 물건 넣고 빼기 판단
        for (int j = 1; j <= k; j++){ // j 무게 계산
            if(j - thing[i].first >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-thing[i].first] + thing[i].second);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];
    return 0;
}

/*dp
( pair(w,v)를 w는 가벼운 순, v은 높은 순으로 정렬 )
>> 0-1 knapsack문제 -> 모든 경우를 다 따질수 밖에 없음 -> 정렬이 필요할까 ?




*/