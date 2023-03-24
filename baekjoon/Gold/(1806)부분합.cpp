/**
 * baekjoon - 1806
 * two pointer, prefix sum
*/

#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> v;

void Input(){
    cin >> N >> S;
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }
}

void Solution(){
    int start, end, minLen, sum;
    start = end = sum = 0;
    minLen = N+1;
    while (start < N){
        if (sum >= S){
            if (minLen > end-start){
                minLen = end-start;
            }
            sum -= v[start];
            start++;
        }

        else if (end != N){
            sum += v[end];
            end++;
        }
        
        else {
            sum -= v[start];
            start++;
        }
    }

    if (minLen == N+1){
        cout << 0;
    }
    else {
        cout << minLen;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}
