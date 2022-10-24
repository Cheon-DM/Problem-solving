/**
 * baekjoon - 2344
 * implementation, bruteforce, simulation
 */

#include <iostream>
#include <vector>

#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    fio;
    //input
    int N, M; cin >> N >> M;
    vector<vector<int>> box;
    box.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> box[i][j]; // 0: 아무것도 없음, 1: 거울
        }
    }

    /**
     * 테두리 : 좌, 하, 우, 상 순서로
     * 거울 부딪힐 때 : 상 -> 우 / 하 -> 좌 / 좌 -> 하 / 우 -> 상
     * 상 : 0, 좌 : 1, 하 : 2, 우 : 3
     */
    //sol
    int hole = 2 * N + 2 * M;
    int hX = 0; int hY = -1; int hDir = 3;
    int p = 0; int q = 0;
    while(hole--){
        if (hole >= N + 2 * M && hole < 2 * N + 2 * M){ 
            hX = p++; hY = -1; hDir = 3;
        }
        else if (hole >= N + M && hole < N + 2 * M){
            hX = p; hY = q++; hDir = 0;
        }
        else if (hole >= M && hole < N + M){
            hX = --p; hY = q; hDir = 1;
        }
        else {
            hX = -1; hY = --q; hDir = 2;
        }

        while(1){
            // light location
            hX += dx[hDir];
            hY += dy[hDir];

            if (hX < 0 || hY < 0 || hX >= N || hY >= M) break;

            if (box[hX][hY] == 1) {
                switch (hDir) {
                case 0:
                    hDir = 3;
                    break;
                case 1:
                    hDir = 2;
                    break;
                case 2:
                    hDir = 1;
                    break;
                case 3:
                    hDir = 0;
                    break;
                }
            }
        }
        if (hX == -1){
            cout << 2 * N + 2 * M - hY <<" ";
        }
        if (hX == N){
            cout << N + (hY+1) << " ";
        }
        if (hY == -1){
            cout << (hX+1) << " ";
        }
        if (hY == M){
            cout << 2*N + M - hX <<" ";
        }
    }

    return 0;
}