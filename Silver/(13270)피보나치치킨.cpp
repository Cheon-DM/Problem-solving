#include <iostream>
#include <vector>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int dp[100000]; // 인원 fibo
int dp2[100000]; // 인원에 대한 최대 닭

void fibo(int n){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int index = 2;
    while(dp[index] <= n){
        index++;
        dp[index] = dp[index-1] + dp[index-2];
    }
}

int main(){
    fio;
    int n; cin >> n;

    fibo(n);

    // min
    int min = 0;
    int tmp = n;
    if (tmp % 2 == 1){
        tmp -= 3;
        min += 2;
    }
    min += (tmp / 2);

    // max
    int chick_max = -1;
    dp2[2] = 1;
    dp2[3] = 2;
    dp2[4] = 2;
    dp2[5] = 3;
    dp2[6] = 4;

    for (int i = 7; i <= n; i++){
        int person = 2;
        while (dp[person] <= i){
            chick_max = max(chick_max, dp2[dp[person]] + dp2[i - dp[person]]);
            person++;
        }

        dp2[i] = chick_max;
    }

    cout << min << " " << dp2[n];

}