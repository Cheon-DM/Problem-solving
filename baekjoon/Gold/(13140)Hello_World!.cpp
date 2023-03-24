/**
 * baekjoon - 13140
 * math, bruteforce
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

/**
 * hello + world = N을 만족하는 서로 다른 한 자리수
 * d, e, h, l, o, r, w 구하기 (h, w는 0이 될 수 없음.)
 * 1. 순열을 이용해 해당 0~9까지 수 중에서 7개 뽑아줌.
 * 2. h, w는 0이 되는 경우 pass.
 * 3. 주어진 입력 값이 만들어지는 지 확인.
 * 4. 만약 만들어지면 출력, 전체 다 돌려보아도 해당 값을 만들 수 없으면 'No Answer' 출력
*/

int helloNumber(vector<int> num){
    return num[2] * 10000 + num[1] * 1000 + num[3] * 100 + num[3] * 10 + num[4];
}

int worldNumber(vector<int> num){
    return num[6] * 10000 + num[4] * 1000 + num[5] * 100 + num[3] * 10 + num[0];
}

void printResult(int hello, int world){
    cout << "  " << hello << "\n";
    cout << "+ " << world << "\n";
    cout << "-------\n";
    cout.width(7);
    cout << hello + world;
}

int main(){
    fio;
    //input
    int N; cin >> N;

    //sol
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool flag = false;
    do{
        vector<int> num;
        for (int i = 0 ; i < v.size(); i++){
            num.push_back(v[i]);
        }

        if (num[2] == 0 || num[6] == 0) continue;

        int hello = helloNumber(num);
        int world = worldNumber(num);

        if (hello + world == N) {
            printResult(hello, world);
            flag = true;
            break;
        }

    } while(next_permutation(v.begin(), v.end()));

    if (!flag) cout << "No Answer";

    return 0;
}