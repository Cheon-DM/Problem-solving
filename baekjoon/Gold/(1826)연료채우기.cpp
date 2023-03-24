#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)

using namespace std;

int main(){
    fio;

    int n; cin >> n;

    vector<pair<int,int>> v1;
    int a, b;
    for(int i = 0 ; i < n; i++){
        cin >> a >> b;
        v1.push_back(make_pair(a,b));
    }
    sort(v1.begin(), v1.end());

    pair<int, int> info;
    cin >> a >> b;
    info.first = a;
    info.second = b;


    int current = 0;
    int count = 0;
    int index = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    while(info.first > info.second){
        while(v1[index].first <= info.second && index < n){
            pq.push(v1[index].second);
            index++;
        }

        if (!pq.empty()){
            info.second += pq.top();
            pq.pop();
            count++;
        }

        else if(index == n || v1[index].first > info.second){
            count = -1;
            break;
        }
    }

    cout << count << "\n";
    return 0;
}

/* greedy

현재 갈 수 있는 연료로 내림차순 정렬 ?
가장 거기까지 간 후 연료 냠냠.
연료를 먹은 후 다시 내림차순 정렬
ex) (4,4), (5,2), (11,5), (15,10), (25,10)
현재 info = (25, 10)
현재 위치 = 0
1. 처음 : (4,4), (5,2) 까지 가능 -> (4,4)로 이동하면 info = (25, 6)
--> 연료 먹음 : info = (25, 10), 현재 위치 = 4
2. 5 ~ 14 : (5,2), (11,5) 까지 가능 -> (11, 5)로 이동하면 info = (25, 3)
--> 연료 먹음 : info = (25, 8), 현재 위치 = 11
3. 12 ~ 19 : (15, 10) 가야함 -> info = (25, 6)
--> 연료 먹음 : info = (25, 16), 현재 위치 = 15

** 남은 연료로 최종 위치 까지 갈 수 있는지 항상 체크.
** 순서에 대한 의문점 : 최대연료만 뽑아서 순서는 최종적으로 되므로 걱정 ㄴㄴㅋㅋ

*/