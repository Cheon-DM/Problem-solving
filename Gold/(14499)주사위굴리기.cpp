/**
 * baekjoon - 14499
 * implementation, simulation
 * */

#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int main(){
    fio;
    //input
    int n, m, cur_x, cur_y, k;
    cin >> n >> m >> cur_x >> cur_y >> k;
    vector<vector<int>> board;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    vector<int> command;
    command.assign(k, 0);
    for (int i = 0; i < k; i++){
        cin >> command[i];
    }

    //sol
    vector<int> dice(7, 0);
    for (int i = 0; i < k; i++){
        int next_dx = cur_x + dx[command[i]];
        int next_dy = cur_y + dy[command[i]];

        if (next_dx < 0 || next_dy < 0 || next_dx >= n || next_dy >= m) continue;

        switch (command[i]) {
            case 1: // E
                dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
                break;
            case 2: // W
                dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
                break;
            case 3: // N
                dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
                break;
            case 4: // S
                dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
                break;
        }

        if (board[next_dx][next_dy] == 0) {
            board[next_dx][next_dy] = dice[6];
            cout << dice[1] << "\n";
        }

        else {
            dice[6] = board[next_dx][next_dy];
            board[next_dx][next_dy] = 0;
            cout << dice[1] << "\n";
        }

        cur_x = next_dx;
        cur_y = next_dy;
    }

    return 0;
}