/**
 * baekjoon - 7868
 * math, bruteforce, sorting, number theory
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

/**
 * 가장 작은 소수 = 2 , 2^60가 10^18보다 큼,
 * 다른 소수(p)는 항상 p^60 > 2^60 이므로, 최대 60제곱으로 해주어 문제 해결
*/

long long MAX = 1e18;

int main(){
    fio;
    //input
    long long p1, p2, p3, i;
    cin >> p1 >> p2 >> p3 >> i;

    //sol
    vector<long long> v;
    
    for (int i = 0; i < 60; i++){
        if (pow(p1, i) > MAX) break;
        
        for (int j = 0; j < 60 - i; j++){
            if (pow(p1, i) * pow(p2, j) > MAX) break;
            
            for (int k = 0; k < 60 - i - j; k++){
                if (i+j+k == 0) continue;

                if (pow(p1, i) * pow(p2, j) * pow(p3, k) > MAX) break;
                
                v.push_back(pow(p1, i) * pow(p2, j) * pow(p3, k));
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v[i-1];

    return 0;
}