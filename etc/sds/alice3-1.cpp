#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10000
using namespace std;

struct Point {
    int x, y;
};

int answer;
int T, N, M, K, R, C;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<string> v;
vector<Point> f;

void BFS(){
    vector<vector<vector<int>>> time, checked;
    time.assign(K, vector<vector<int>>(N+1, vector<int>(M+1, -1)));
    checked.assign(K, vector<vector<int>>(N+1, vector<int>(M+1, 0)));

    for (int a = 0; a < f.size(); a++){
        queue<Point> q;
        q.push({f[a].x, f[a].y});
        checked[a][f[a].x][f[a].y] = 1;
        time[a][f[a].x][f[a].y] = 0;

        while (!q.empty()){
            Point Cur = q.front(); q.pop();

            for (int i = 0; i < 4; i++){
                int nx = Cur.x + dx[i];
                int ny = Cur.y + dy[i];

                if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

                if (v[nx][ny] == '#') continue;

                if (checked[a][nx][ny] == 0){
                    checked[a][nx][ny] = 1;
                    q.push({nx, ny});
                    time[a][nx][ny] = time[a][Cur.x][Cur.y] + 1;
                }
            }
        }
    }
    


    for (int n = 1; n <= N; n++){
        for (int m = 1; m <= M; m++){
            int t = 0;
            for (int k = 0; k < K; k++){
                if (time[k][n][m] == -1) break;

                t = max(t, time[k][n][m]);
                if (k == K-1){
                    if (t < answer) answer = t;
                }                
            }
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    
    for (int test = 1; test <= T; test++){
        v.clear();
        f.clear();

        cin >> N >> M >> K;
        v.assign(N+1, "");
        string str;
        for (int i = 1; i <= N; i++){
            cin >> str;
            str = "." + str;
            v[i] = str;
        }

        for (int k = 0; k < K; k++){
            cin >> R >> C;
            f.push_back({R, C});
        }

        answer = MAX;
        BFS();
        if (answer == MAX) {
            cout << "#" << test << " -1\n";
        } else {
            cout << "#" << test << " " << answer << "\n";
        }
    }
}