/**
 * baekjoon - 1744
 * greedy, sorting, case work
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> pos, neg;

void Input(){
    cin >> N;
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        
        if (num <= 0){
            neg.push_back(num);
        }
        else {
            pos.push_back(num);
        }
    }
}

void Solution(){
    int ans = 0;
    sort(neg.begin(), neg.end(), less<>());
    sort(pos.begin(), pos.end(), greater<>());

    // neg
    for (int i = 0; i < neg.size(); i = i+2){
        if (neg.size() == 1){
            ans += neg[i];
            break;
        }

        if (i+1 < neg.size()){
            if (ans + (neg[i] * neg[i+1]) > ans + (neg[i] + neg[i+1])){
                ans += (neg[i] * neg[i+1]);
            }
            else {
                ans += (neg[i] + neg[i+1]);
            }
        }

        else {
            ans += neg[i];
        }
    }

    // pos
    for (int i = 0; i < pos.size(); i = i+2){
        if (pos.size() == 1){
            ans += pos[i];
            break;
        }

        if (i+1 < pos.size()){
            if (ans + (pos[i] * pos[i+1]) > ans + (pos[i] + pos[i+1])){
                ans += (pos[i] * pos[i+1]);
            }
            else {
                ans += (pos[i] + pos[i+1]);
            }
        }

        else {
            ans += pos[i];
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();
    
    return 0;
}