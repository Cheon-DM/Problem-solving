/**
 * baekjoon - 11399
 * greedy, sorting
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
vector<int> v;

void Input(){
    cin >> N;
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }
}

void Solution(){
    sort(v.begin(), v.end());
    answer = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            answer += v[j];
        }
    }

    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();
}