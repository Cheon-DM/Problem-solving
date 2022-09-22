/**
 * baekjoon - 1065
 * bruteforcing 
 */

#include <iostream>
using namespace std;

int tmp = 1;
int cnt = 0;

void sol(int num){

    string numStr = "";

    while (num >= tmp){
        int dif = 10;
        numStr = to_string(tmp);

        // 한자리수 & 두자리수
        if (numStr.length() == 1 || numStr.length() == 2) cnt++;

        // 세자리수 이상
        else {
            for (int i = 0; i < numStr.length() - 1; i++) {
                if (i == 0) {
                    dif = numStr[i + 1] - numStr[i];
                    continue;
                }

                if (dif != numStr[i + 1] - numStr[i]) {
                    break;
                }

                if (i == numStr.length() - 2) cnt++;
            }
            
        }

        tmp++;
    }
}

int main(){
    // input
    int n; cin >> n;

    // sol
    sol(n);

    // output
    cout << cnt;
    
    return 0;
}