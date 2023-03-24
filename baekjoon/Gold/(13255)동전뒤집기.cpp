/**
 * baekjoon - 13255
 * math, dp, probability, linearity of expectation
 */

#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int N, K;
int A[51];
double dp[51];

double expected(double a, int k){
    double tmp = 0.0;
    tmp += a * (1 - (double)k/N);
    tmp += (N-a) * ((double)k/N);
    return tmp;
}

void Input(){
    fio;
    cin >> N;
    cin >> K;
    for (int i = 1; i <= K; i++){
        cin >> A[i];
    }
}

void Solution(){
    dp[0] = N;
    int index = 1;
    while(index <= K){
        dp[index] = expected(dp[index-1], A[index]);
        index++;
    }
}

int main(){
    Input();
    Solution();

    cout.fixed;
    cout.precision(10);
    cout << dp[K];

    return 0;
}