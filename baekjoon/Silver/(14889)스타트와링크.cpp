#include <iostream>
#include <algorithm>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, totalA, totalB, tmp;
int _min = 1000; // 두 팀의 능력치 최소값
int arr[21][21] = {0, }; // 입력값 저장
bool chk[21] = {0, };
int cur = 1;

void sol(int step){
    if (step == (n/2)){
        totalA = 0;
        totalB = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(chk[i]&&chk[j]) totalA += arr[i][j];
                if(!chk[i]&&!chk[j]) totalB += arr[i][j];
            }
        }

        _min = min(_min, abs(totalA - totalB));
        return;
    }

    for (int i = cur; i <= n; i++){
        if (!chk[i]){
            chk[i] = true;
            tmp = cur; 
            cur = i;

            sol(step+1); // 다음 단계 이동

            chk[i] = false; // 만약 선택되지 않은 경우 false
            cur = tmp;
        }
    }
}

int main(){
    fio;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    sol(0);
    cout << _min;
    return 0;
}

