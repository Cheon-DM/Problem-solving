/**
 * baekjoon - 18290
 * bruteforce, backtracking
 */

#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m, k;
int arr[10][10];
bool chk[10][10];
int _max = -987654321;

void backtracking(int level, int sum){
    if (level == k){
        if (_max < sum) _max = sum;
        return;
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(!chk[i][j]){
                if (i-1 >= 0 && chk[i-1][j]) continue;
                if (i+1 < n && chk[i+1][j]) continue;
                if (j-1 >= 0 && chk[i][j-1]) continue;
                if (j+1 < m && chk[i][j+1]) continue;

                chk[i][j] = true;
                backtracking(level+1, sum+arr[i][j]);
                chk[i][j] = false;
            }
        }
    }
}

int main(){
    fio;
    //input
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    //sol    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            chk[i][j] = false;
    }

    backtracking(0, 0);

    cout << _max;

    return 0;
}