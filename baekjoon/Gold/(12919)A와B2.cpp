/**
 * baekjoon - 12919
 * implementation, string, bruteforce, recursion
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void sol(string S, string T){
    if (S == T) {
        cout << 1;
        exit(0);
    }

    if (S.length() >= T.length()) return;

    if (T[T.length()-1] == 'A'){
        string tmp = T;
        tmp.erase(tmp.length()-1);
        sol(S, tmp);
    }

    if (T[0] == 'B'){
        string tmp = T;
        reverse(tmp.begin(), tmp.end());
        tmp.erase(tmp.length()-1);
        sol(S, tmp);
    }
}


int main(){
    fio;
    //input
    string S, T;
    cin >> S >> T;

    //sol
    sol(S, T);
    cout << 0;
    
    return 0;
}