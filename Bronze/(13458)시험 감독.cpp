/**
 * baekjoon - 13458
 * math
 * */

#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    long long n, b, c;
    cin >> n;
    vector<long long> spot(n);
    for (int i = 0; i < n; i++){
        cin >> spot[i];
    }
    cin >> b >> c;

    //sol
    long long answer = 0;
    for (int i = 0; i < n; i++){
        spot[i] -= b;
        answer++;
        if (spot[i] <= 0) continue;
        else {
            long long cnt = spot[i] / c;
            if (spot[i] % c != 0) cnt++;
            answer += cnt;
        }
    }

    cout << answer;

    return 0;
}