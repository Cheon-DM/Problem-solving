/**
 * baekjoon - 16926
 * implementation
 */

#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n, m, r;
    cin >> n >> m >> r;
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    while(r--){
        int x1 = 0; int y1 = 0;
        int x2 = 0; int y2 = m-1;
        int x3 = n-1; int y3 = m-1;
        int x4 = n-1; int y4 = 0;

        // 한 바퀴
        while (x1<x4 && y1<y2){
            int tmp = arr[x1][y1];

            // 위쪽
            for (int i = y1; i < y2; i++) arr[x1][i] = arr[x1][i+1];

            // 오른쪽
            for (int i = x2; i < x3; i++) arr[i][y2] = arr[i+1][y2];

            // 아래쪽
            for (int i = y3; i > y4; i--) arr[x3][i] = arr[x3][i-1];

            // 왼쪽
            for (int i = x4; i > x1; i--) arr[i][y4] = arr[i-1][y4];

            // 처음
            arr[x1+1][y1] = tmp;

            
            // 안쪽으로 이동
            x1 += 1; y1 += 1;
            x2 += 1; y2 -= 1;
            x3 -= 1; y3 -= 1;
            x4 -= 1; y4 += 1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
 
    return 0;
}