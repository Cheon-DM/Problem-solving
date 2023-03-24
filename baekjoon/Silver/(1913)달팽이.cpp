/**
 * baekjoon - 1913
 * implementation
 */

#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    fio;
    //input
    int n, target;
    cin >> n;
    cin >> target;

    //sol
    int nX = n / 2;
    int nY = n / 2;
    int arr[n][n];
    int num = 1;
    int dir = 0;
    int cnt = 0;
    int p = 1;
    
    //insert '1'
    arr[nX][nY] = num++;

    while (1){
        //end
        if (num > n*n) break;

        //move & insert
        for (int i = 1; i <= p; i++){
            nX += dx[dir];
            nY += dy[dir];
            arr[nX][nY] = num++;
        }
        
        // cnt increase, and dir change
        cnt++;
        dir++;
        if (dir == 4) dir = 0;

        if (cnt >= 2){
            if (p == n-1 && cnt != 3) {
                cnt++;
            }
            else {
                cnt = 0;
                p++;
            }
        }

    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == target) {
                cout << i+1 <<" " << j+1;
            }
        }
    }

    return 0;
}