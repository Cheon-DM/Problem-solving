/**
 * baekjoon - 1038
 * bruteforce, backtracking 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int N;
vector<long long> downNumber;

void Input(){
    cin >> N;
}

void DFS(long long index, int cnt){
    if (cnt > 10) return;

    downNumber.push_back(index);
    for (int i = 0; i < 10; i++){
        if (index % 10 > i){
            DFS(index * 10 + i, cnt + 1);
        }
    }

    return;
}

void Solution(){
    for (int i = 0; i < 10; i++){
        DFS(i, 1);
    }
}

int main(){
    fio;

    Input();
    Solution();
    sort(downNumber.begin(), downNumber.end());

    if (downNumber.size() <= N) {
        cout << -1;
    } else {
        cout << downNumber[N];
    }

    return 0;
}