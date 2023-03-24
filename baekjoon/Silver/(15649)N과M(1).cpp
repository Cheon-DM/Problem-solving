#include <iostream>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
int result[9] = {0, };
bool chk[9] = {0, };

void sol(int level){
    if(level == m){ // m개 선택했을 때
        for (int i = 0; i < m; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }


    // 아직 m개를 다 선택하지 않은 경우
    for (int i = 1; i <= n; i++){ // 처음(1)부터 n까지
        if (!chk[i]){ // 해당 숫자(i) 선택 안했을 때
            chk[i] = true; // 선택
            result[level] = i; // 결과에 추가
            sol(level+1); // 다음 단계 이동
            chk[i] = false; // 만약 선택되지 않은 경우 false
        }
    }
    
}

int main(){
    fio;    
    cin >> n >> m;

    // 1 ~ n까지 자연수 중 중복 없이 순서 상관 있게 m개를 고르는 경우 모두 구하기
    sol(0);
    return 0;

}