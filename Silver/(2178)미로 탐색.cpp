/**
 * baekjoon - 2178
 * bfs
*/

#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N, M;
int maze[101][101] = {0, };
int dist[101][101] = {0, };

void Input(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        for (int j = 0; j < M; j++){
            maze[i][j] = str[j] - '0';
        }
    }
}

void BFS(){
    queue<pair<int,int>> q;
    int visited[101][101] = {0, };
    visited[0][0] = 1;
    q.push({0,0});
    dist[0][0] = 1;

    while (!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maze[nx][ny] == 0) continue;

            if (visited[nx][ny] != 1){
                q.push({nx, ny});
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }

    cout << dist[N-1][M-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    BFS();

    return 0;
}