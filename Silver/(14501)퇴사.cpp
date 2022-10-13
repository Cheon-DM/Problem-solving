/**
 * baekjoon - 14501
 * dp, bruteforce
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n, t, p;
    vector<pair<int, int>> schedule;
    cin >> n;
    schedule.assign(n + 1, make_pair(0, 0));
    for (int i = 1; i <= n; i++){
        cin >> t >> p;
        schedule[i] = make_pair(t, p);
    }

    //sol
    vector<int> dp(n + 2, 0);
    int deadline;
    for (int i = n; i > 0; i--){
        // select current date & calculate deadline
        deadline = i + schedule[i].first;
        if (deadline > n + 1) { // consulting 'X'
            dp[i] = dp[i+1];
        }
        else { // consulting 'O'
            dp[i] = max(dp[i+1], dp[deadline] + schedule[i].second);
        }
    }

    cout << dp[1];

    return 0;
}