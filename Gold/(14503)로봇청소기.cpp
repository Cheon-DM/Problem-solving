#include <iostream>
#include <cstring>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m, r, c, d;
int arr[50][50] = {-1, };
int cnt = 0;
int tryChange = 0;

void sol(){
    while(1){
        if (arr[r][c] == 0){
            arr[r][c] = 2;
            //cout <<"(" << r << ", "<<c<<")"<<endl;
            cnt++;
        }
        if (tryChange == 4){
            switch (d)
            {
            case 0:
                r++;
                break;
            case 1:
                c--;
                break;
            case 2:
                r--;
                break;
            case 3:
                c++;
                break;
            default:
                break;
            }

            tryChange = 0;
            if (arr[r][c] == 1) break;
        }

        if (d == 0){
            d = 3;
            if (arr[r][c-1] == 0){
                c--;
                tryChange = 0;
            }
            else {
                tryChange++;
            }

            continue;
        }

        if (d == 1){
            d = 0;
            if (arr[r-1][c] == 0){
                r--;
                tryChange = 0;
            }
            else {
                tryChange++;
            }

            continue;
        }

        if (d == 2){
            d = 1;
            if (arr[r][c+1] == 0){
                c++;
                tryChange = 0;
            }
            else {
                tryChange++;
            }

            continue;
        }

        if (d == 3){
            d = 2;
            if (arr[r+1][c] == 0){
                r++;
                tryChange = 0;
            }
            else {
                tryChange++;
            }

            continue;
        }
    }
}

int main(){
    //input
    fio;
    for (int i = 0; i <= 51; i++){
        memset(arr, -1, sizeof(arr[i]));
    }
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    //sol
    sol();
    cout << cnt;


    return 0;
}