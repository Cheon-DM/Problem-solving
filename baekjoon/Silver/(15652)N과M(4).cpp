#include <iostream>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
int cur = 1;
int tmp;
int result[9] = {0, };

void sol(int level){
    if(level == m){ // m개 선택했을 때
        for (int i = 0; i < m; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }


    // 아직 m개를 다 선택하지 않은 경우
    for (int i = cur; i <= n; i++){ // 처음(1)부터 n까지,
        result[level] = i; // 결과에 추가
        tmp = cur; // tmp에 cur를 잠시 저장
        cur = i; // 다음 단계에 쓰기 위해 cur를 i로 바꿈
        sol(level+1); // 다음 단계 이동
        cur = tmp; // 선택되지 않았으므로 cur를 원상태로 돌림
    }
    
}

int main(){
    fio;    
    cin >> n >> m;

    // 1 ~ n까지 자연수 중 중복 가능하고 순서 상관없게 m개를 고르는 경우 모두 구하기
    sol(0);
    return 0;

}