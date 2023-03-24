/**
 * baekjoon - 1021
 * deque
 */

#include <iostream>
#include <deque>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n, m; cin >> n >> m;
    int num;
    deque<int> dq;
    vector<int> v;
    for (int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++){
        cin >> num;
        v.push_back(num);
    }    

    //sol
    int answer = 0;
    int position;
    for (int i = 0; i < m; i++){

        for (int j = 0; j < n; j++){ // index find
            if(v[i] == dq.at(j)){
                position = j;
                break;
            }
        }

        if (position <= dq.size() / 2){
            for (int j = 0; j < position; j++){
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }

            dq.pop_front();
        }

        else {
            for (int j = 0; j < dq.size() - position; j++){
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }

            dq.pop_front();
        }

    }

    cout << answer;

    return 0;
}