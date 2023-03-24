/**
 * baekjoon - 1753
 * graph theory, Dijkstra
*/

#include <iostream>
#include <vector>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define INF 987654321
using namespace std;

int V, E, K;
vector<pair<int, int>> Map[20001];
int Dis[20001];

void Input(){
    fio;
    cin >> V >> E >> K;

    // 초기화
    fill(&Dis[0], &Dis[20001], INF);

    int start, end, w;
    for (int i = 0; i < E; i++){
        cin >> start >> end >> w;
        Map[start].push_back({end, w});
    }
}

void Solution(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    Dis[K] = 0;

    while(!pq.empty()){
        // 우선순위를 위해 pq에 넣을 때 -(마이너스)를 붙여서 넣었으므로, pop시 -(마이너스) 다시 붙여야함
        int weight = -pq.top().first;
        int start = pq.top().second;
        pq.pop();

        for (int i = 0; i < Map[start].size(); i++){
            int end = Map[start][i].first;
            int cost = Map[start][i].second;

            if (Dis[end] > weight + cost){
                Dis[end] = weight + cost;
                pq.push({-Dis[end], end});
            }
        }
    }
}

int main(){
    Input();
    Solution();

    for (int i = 1; i <= V; i++){
        if (Dis[i] == INF) cout << "INF\n";
        else cout << Dis[i] << "\n";
    }

    return 0;
}