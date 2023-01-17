#include <iostream>
#include <vector>
using namespace std;

int T, N, M, K;
vector<vector<int>> v;
int MaxAnswer = 0;

void CalMax(vector<vector<int>> origin){
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= M; j++){
            if (origin[i][j] > MaxAnswer){
                MaxAnswer = origin[i][j];
            }
        }
    }
}

void Move(int level, vector<vector<int>> board) {
    if (level == K) {
        CalMax(board);
        return;
    }
    
    vector<vector<int>> Copy(board);

    // 동
    for (int k = 1; k <= N; k++){
        for (int j = M; j >= 1; j--){
            if (j == 1) break;

            if (Copy[k][j] > 0){
                Copy[k][j-1] += Copy[k][j];
                Copy[k][j] = 0;
                break;
            }
        }
    }
    Move(level+1, Copy);
    copy(board.begin(), board.end(), Copy.begin());

    // 서
    for (int k = 1; k <= N; k++){
        for (int j = 1; j <= M; j++){
            if (j == M) break;

            if (Copy[k][j] > 0){
                Copy[k][j+1] += Copy[k][j];
                Copy[k][j] = 0;
                break;
            }
        }
    }
    Move(level+1, Copy);
    copy(board.begin(), board.end(), Copy.begin());
    
    // 남
    for (int k = 1; k <= M; k++){
        for (int i = N; i >= 1; i--){
            if (i == 1) break;

            if (Copy[i][k] > 0){
                Copy[i-1][k] += Copy[i][k];
                Copy[i][k] = 0;
                break;
            }
        }
    }
    Move(level+1, Copy);
    copy(board.begin(), board.end(), Copy.begin());

    // 북
    for (int k = 1; k <= M; k++){
        for (int i = 1; i <= N; i++){
            if (i == N) break;

            if (Copy[i][k] > 0){
                Copy[i+1][k] += Copy[i][k];
                Copy[i][k] = 0;
                break;
            }
        }
    }
    Move(level+1, Copy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int test = 1; test <= T; test++){
        //input
        cin >> N >> M >> K;
        v.assign(N+1, vector<int>(M+1));
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cin >> v[i][j];
            }
        }

        Move(0, v);
        cout << "#" << test << " " << MaxAnswer << endl;
        MaxAnswer = 0;
    }
}