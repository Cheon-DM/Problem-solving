/**
 * baekjoon - 9663
 * backtracking, bruteforcing */

#include <iostream>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n;
int col[15];
int cnt = 0;

bool isPromising(int level){
    for (int i = 0; i < level; i++){
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) return false;
    }

    return true;
}

void nqueen(int num){
    if (num == n){
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++){
        col[num] = i; // (num, i)
        if (isPromising(num)) nqueen(num+1);
    }

}


int main(){
    // input
    fio;
    cin >> n;

    // sol
    nqueen(0);
    cout << cnt;
    return 0;
}