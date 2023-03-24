/* bfs */

#include <iostream>
#include <string.h>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

typedef struct {
    int x, y, z;
} types;


int m, n, h; // m = 가로, n = 세로, h = 높이
int box[102][102][102];
bool chk[102][102][102] = {false, };
queue<types> q;
int cnt = 0;

void bfs(){
    while(!q.empty()){
        queue<types> tmp = q;
        q = queue<types>();

        while (!tmp.empty()){
            types frt = tmp.front();
            tmp.pop();

            if (box[frt.x - 1][frt.y][frt.z] == 0) {
                box[frt.x - 1][frt.y][frt.z] = 1;
                chk[frt.x - 1][frt.y][frt.z] = true;
                q.push({frt.x - 1, frt.y, frt.z});
            }

            if (box[frt.x + 1][frt.y][frt.z] == 0) {
                box[frt.x + 1][frt.y][frt.z] = 1;
                chk[frt.x + 1][frt.y][frt.z] = true;
                q.push({frt.x + 1, frt.y, frt.z});
            }

            if (box[frt.x][frt.y - 1][frt.z] == 0) {
                box[frt.x][frt.y - 1][frt.z] = 1;
                chk[frt.x][frt.y - 1][frt.z] = true;
                q.push({frt.x, frt.y - 1, frt.z});
            }

            if (box[frt.x][frt.y + 1][frt.z] == 0) {
                box[frt.x][frt.y + 1][frt.z] = 1;
                chk[frt.x][frt.y + 1][frt.z] = true;
                q.push({frt.x, frt.y + 1, frt.z});
            }

            if (box[frt.x][frt.y][frt.z - 1] == 0) {
                box[frt.x][frt.y][frt.z - 1] = 1;
                chk[frt.x][frt.y][frt.z - 1] = true;
                q.push({frt.x, frt.y, frt.z - 1});
            }

            if (box[frt.x][frt.y][frt.z + 1] == 0) {
                box[frt.x][frt.y][frt.z + 1] = 1;
                chk[frt.x][frt.y][frt.z + 1] = true;
                q.push({frt.x, frt.y, frt.z + 1});
            }
        }

        cnt++;
    }
}

int main(){
    fio;
    cin >> m >> n >> h;
    memset(box, -1, sizeof(box));

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                cin >> box[i][j][k];

                if (box[i][j][k] == -1) chk[i][j][k] = true;
                if (box[i][j][k] == 1) {
                    chk[i][j][k] = true;
                    q.push({i, j, k});
                }
            }
        }
    }

    bfs();

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= m; k++){
                if (!chk[i][j][k]){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << cnt -1;
    return 0;
}