#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main() {
    fio;

    int n; cin >> n;
    int seq[n+1];
    for (int i = 1; i < n+1; i++){
        cin >> seq[i];
    }

    int dp[n+1] = {0}; // 부분 수열 길이
    int sub[n+1] = {0, }; // 부분 수열
    dp[1] = 1;
    sub[1] = seq[1];

    int _max = dp[1];
    int sub_max = 1;

    for (int i = 2; i <= n ; i++){
        int sub_index = 1;

        for (int j = 1; j <= sub_max; j++){ // 이전 부분 수열 값 < 현재 수열 값
            if(sub[j] < seq[i]) sub_index++;
        }

        if (sub_index > sub_max) {            
            sub_max = sub_index;            
            sub[sub_max] = seq[i];
            dp[i] = _max + 1;
        }

        else {
            sub[sub_index] = seq[i];
            dp[i] = dp[sub_index];
        }

        _max = max(_max, dp[i]);
    }

    cout << _max;

}