/**
 * baekjoon - 1715
 * data structure, greedy, priorty queue
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
int answer = 0;
priority_queue<int, vector<int>, greater<>> pq;

void Input(){
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        pq.push(tmp);
    }
}

void Solution(){
    while (pq.size() >= 2){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(first+second);
        answer += first+second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    cout << answer;

    return 0;
}