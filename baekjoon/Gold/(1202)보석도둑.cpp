/**
 * baekjoon - 1202
 * data structure, greedy, sorting, priority queue
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

vector<pair<int,int>> jewel; // 무게, 가격
vector<int> bag; // 가방

int main(){
    fio;
    //input
    int n, k, m, v, c;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> m >> v;
        jewel.push_back(make_pair(m, v));
    }

    for (int i = 0 ; i < k; i++){
        cin >> c;
        bag.push_back(c);
    }

    // sol
    int cnt = 0;
    long long result = 0;
    int index = 0;
    priority_queue<int> pq;

    // sorting
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    // greedy
    for (int i = 0; i < k; i++){
        while(index < n && jewel[index].first <= bag[i]){ // 해당 가방에 넣을 수 있는 보석 모두 넣기
            pq.push(jewel[index++].second);
        }

        if (!pq.empty()){
            result += (long long)pq.top();
            pq.pop();
        }
    }

    cout << result;


    return 0;
}