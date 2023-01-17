/**
 * baekjoon - 2003
 * two pointer
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void Input(){
    cin >> N >> M;
    int a;
    for (int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }
}

void Solution(){
    int s, e, cnt, sum;
    s = e = cnt = sum = 0;

    while (s < N){
        if (sum == M){
            cnt++;
        }

        if (sum >= M || e == N){
            sum -= v[s];
            s++;
        }

        else {
            sum += v[e];
            e++;
        }
    }

    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}