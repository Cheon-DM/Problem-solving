/**
 * baekjoon - 16236
 * implementation, graph, bfs, simulation
 * */

#include <iostream>
#include <vector>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n;
int cnt = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> spot;
vector<vector<int>> dis;

void bfs(int curX, int curY, int size){
    int distance = 0;
    queue<pair<int, int>> q; // x, y, dis
    q.push({curX, curY});
    dis[curX][curY] = 0;

    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(n, false));
    visited[curX][curY] = true;

    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nextX = cx + dx[i];
            int nextY = cy + dy[i];

            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue; // no access

            if (spot[nextX][nextY] > size) continue; // no pass

            if (!visited[nextX][nextY]) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = true;
                dis[nextX][nextY] = dis[cx][cy] + 1;

                if (size > spot[nextX][nextY] && spot[nextX][nextY] != 0) { // eat
                    cnt++;
                }
            }

            
        }
    }
}

int main(){
    fio;
    //input
    cin >> n;    
    spot.assign(n, vector<int>(n));
    pair<int, int> shark;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> spot[i][j];

            if (spot[i][j] == 9) shark = make_pair(i, j);
        }
    }

    //sol
    int size = 2;
    int time = 0;
    int eat = 0;

    while (1){
        bool flag = false;
        dis.assign(n, vector<int>(n, 401));

        bfs(shark.first, shark.second, size);

        if (cnt == 0) break;

        int min_dis = 401;
        pair<int, int> fish_xy;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (min_dis > dis[i][j] && dis[i][j] != 0 && spot[i][j] != 0 && spot[i][j] < size) {
                    min_dis = dis[i][j];
                    fish_xy = {i, j};
                    flag = true;
                }
            }
        }

        if (!flag) break;

        time += dis[fish_xy.first][fish_xy.second];
        spot[fish_xy.first][fish_xy.second] = 0;
        spot[shark.first][shark.second] = 0;
        cnt--;
        eat++;
        shark = fish_xy;

        if (size == eat) {
            eat = 0;
            size++;
        }
    }
    
    cout << time;

    return 0;
}