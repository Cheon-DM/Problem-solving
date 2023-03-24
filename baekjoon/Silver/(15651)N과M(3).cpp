#include <iostream>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
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
    for (int i = 1; i <= n; i++){ // 처음(1)부터 n까지,
        result[level] = i; // 결과에 추가
        sol(level+1); // 다음 단계 이동

        /*
        * (1), (2)문제와는 다르게 중복이 가능하므로 숫자가 들어가는지 체크를 하지 않아도 되고 m를 선택하기만 하면 됨.
        */
    }
    
}

int main(){
    fio;    
    cin >> n >> m;

    // 1 ~ n까지 자연수 중 중복 가능하고 순서 상관있게 m개를 고르는 경우 모두 구하기
    sol(0);
    return 0;

}