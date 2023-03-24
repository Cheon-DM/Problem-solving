/**
 * baekjoon - 19236
 * implementation, simulation, backtracking
 */

#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

struct Fish {
    int x;
    int y;
    int dir;
    bool isDead;
};

int _max = 0;
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void move(int spot[][4], Fish fish[], int shark_x, int shark_y){
    for (int i = 1; i <= 16; i++){
        if (fish[i].isDead == true) continue;

        int nX = fish[i].x + dx[fish[i].dir];
        int nY = fish[i].y + dy[fish[i].dir];

        // 반시계방향
        while(nX < 0 || nY < 0 || nX >= 4 || nY >= 4 ||(nX == shark_x && nY == shark_y)){
            fish[i].dir += 1;
            if (fish[i].dir >= 9) fish[i].dir = 1;
            
            nX = fish[i].x + dx[fish[i].dir];
            nY = fish[i].y + dy[fish[i].dir];
        }

        // swap
        if (spot[nX][nY] == -1){ // 빈칸으로 이동
            spot[nX][nY] = i;
            spot[fish[i].x][fish[i].y] = -1;

            fish[i].x = nX;
            fish[i].y = nY;
        }

        else { // 물고기 교환
            int tmpFish = spot[nX][nY];
            spot[nX][nY] = i;
            spot[fish[i].x][fish[i].y] = tmpFish;

            fish[tmpFish].x = fish[i].x;
            fish[tmpFish].y = fish[i].y;
            fish[i].x = nX;
            fish[i].y = nY;
        }
    }
}

void backtracking(int spot[][4], Fish fish[], int shark_x, int shark_y, int sum){
    // copy spot & fish
    int C_spot[4][4];
    Fish C_fish[17];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            C_spot[i][j] = spot[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) C_fish[i] = fish[i];

    // eat fish
    int targetFish = C_spot[shark_x][shark_y];
    int shark_dir = C_fish[targetFish].dir;
    C_fish[targetFish].isDead = true;
    C_spot[shark_x][shark_y] = -1;
    sum += targetFish;

    if (_max < sum) _max = sum;

    move(C_spot, C_fish, shark_x, shark_y);

    for (int i = 1; i <= 3; i++){
        int nX = shark_x + i * dx[shark_dir];
        int nY = shark_y + i * dy[shark_dir];

        if (nX < 0 || nY < 0 || nX >= 4 || nY >= 4) break;

        if (C_spot[nX][nY] == -1) continue;

        backtracking(C_spot, C_fish, nX, nY, sum);
    }
}

int main(){
    fio;
    //input
    Fish fish[17];
    int spot[4][4]; // 1~16: fish, -1; die fish
    int a, b;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> a >> b;
            spot[i][j] = a;
            fish[a].x = i;
            fish[a].y = j;
            fish[a].dir = b;
            fish[a].isDead = false;
        }
    }

    backtracking(spot, fish, 0, 0, 0);

    cout << _max;

    return 0;
}