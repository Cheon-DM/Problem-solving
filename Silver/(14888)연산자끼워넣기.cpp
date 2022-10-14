/**
 * baekjoon - 14888
 * bruteforce, backtracking, permutation
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n; cin >> n;
    int num[4];
    vector<int> a(n);
    vector<string> oper;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> num[i];
    }

    //sol
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            for (int j = 0; j < num[i]; j++){
                oper.push_back("+");
            }
        }
        if (i == 1) {
            for (int j = 0; j < num[i]; j++){
                oper.push_back("-");
            }
        }
        if (i == 2) {
            for (int j = 0; j < num[i]; j++){
                oper.push_back("*");
            }
        }
        if (i == 3) {
            for (int j = 0; j < num[i]; j++){
                oper.push_back("/");
            }
        }
    }

    sort(oper.begin(), oper.end());

    long long _min = 999999999;
    long long _max = -999999999;
    int index = 0;

    do {
        int result = a[index++];
        for (auto it = oper.begin(); it != oper.end(); ++it){
            if (*it == "+"){
                result = result + a[index++];
            }
            else if (*it == "-"){
                result = result - a[index++];
            }
            else if (*it == "*"){
                result = result * a[index++];
            }
            else if (*it == "/"){
                if (result < 0) {
                    result = -((-result) / a[index++]);
                }
                else result = result / a[index++];
            }
        }
            
        if (_min > result) _min = result;
        if (_max < result) _max = result;
        index = 0;
    } while (next_permutation(oper.begin(), oper.end()));

    cout << _max << "\n" << _min;

    return 0;
}