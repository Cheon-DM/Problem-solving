#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Point{
    int x, y;
};

struct Info{
    int minMove;
    int sumDisBread;
    bool visit;
};

int T, N, M, R, C;
int arr[11][11];
Info info[11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void Init(){
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 11; j++){
            arr[i][j] = 0;
        }
    }
}

void SettingMapInfo(int dis){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            info[i][j].minMove = 0;
            info[i][j].sumDisBread = dis;
            info[i][j].visit = false;
        }
    }
}

int CalDis(int x, int y){
    return abs(C-y)+abs(R-x);
}

void BFS(Point start){
    queue<Point> q;
    q.push(start);
    info[start.x][start.y].sumDisBread -= CalDis(start.x, start.y);
    info[start.x][start.y].visit = true;

    while(!q.empty()){
        Point Cur = q.front();
        q.pop();

        // 과자집 도착
        if (Cur.x == N && Cur.y == M) {
            return;
        }

        for (int i = 0; i < 4; i++){
            int nx = Cur.x + dx[i];
            int ny = Cur.y + dy[i];

            // 경계값
            if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

            // 빈 곳
            if (arr[nx][ny] == 0) continue;

            // 빵 부스러기 찾음
            if (arr[nx][ny] == 1){
                if (!info[nx][ny].visit){
                    info[nx][ny].visit = true;
                    info[nx][ny].minMove = info[Cur.x][Cur.y].minMove + 1;
                    info[nx][ny].sumDisBread = info[Cur.x][Cur.y].sumDisBread - CalDis(nx, ny);
                    q.push({nx, ny}); 
                }
                else {
                    if (info[nx][ny].minMove == info[Cur.x][Cur.y].minMove + 1){ // 최소 횟수가 같을 때
                        if (info[nx][ny].sumDisBread > info[Cur.x][Cur.y].sumDisBread - CalDis(nx, ny)){
                            info[nx][ny].minMove = info[Cur.x][Cur.y].minMove + 1;
                            info[nx][ny].sumDisBread = info[Cur.x][Cur.y].sumDisBread - CalDis(nx, ny);
                        }
                    }
                }
                
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int Testcase = 1; Testcase <= T; Testcase++){
        cin >> N >> M >> R >> C;
        Init();
        int dis = 0;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 1){
                    dis += CalDis(i, j);
                }
            }
        }

        SettingMapInfo(dis);

        BFS({1, 1});
        cout << "#" << Testcase << " "  << info[N][M].minMove << " " << info[N][M].sumDisBread << "\n";
    }

    return 0;
}
