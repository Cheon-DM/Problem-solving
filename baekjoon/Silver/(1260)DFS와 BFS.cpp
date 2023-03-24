/**
 * baekjoon - 1260
 * dfs, bfs
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> v;
vector<bool> visited;

void Input(){
    cin >> N >> M >> V;
    int x,y;
    v.assign(N+1, vector<int>());
    for (int i = 0; i < M; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= N; i++){
        sort(v[i].begin(), v[i].end());
    }
}

void DFS(int start){
    visited[start] = true;
    cout << start << " ";

    for (int i = 0 ; i < v[start].size(); i++){
        int cur = v[start][i];
        if (!visited[cur]){
            DFS(cur);
        }
    }
}

void BFS(int start){
    visited.assign(N+1, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (auto next: v[cur]){
            if (!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    visited.assign(N+1, false);
    DFS(V);
    cout << "\n";
    BFS(V);

    return 0;
}