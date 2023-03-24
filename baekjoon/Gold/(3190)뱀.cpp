/**
 * baekjoon - 3190
 * implementation, simulation, deque, queue
 * */

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    fio;
    //input
    int n, k, c, r, l, t;
    char d;
    cin >> n;

    cin >> k;
    vector<vector<int>> board;
    board.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k; i++){
        cin >> c >> r;
        board[c][r] = 1; // chk apple
    }
    
    cin >> l;
    map<int, char> chg;
    for (int i = 0; i < l; i++){
        cin >> t >> d;
        chg[t] = d;
    }

    //sol
    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    int snake_dir = 1;  // snake's (x, y, dir)
    vector<vector<bool>> chk; // snake length checking -> true : snake body / false : no
    chk.assign(n+1, vector<bool>(n+1, false));
    chk[1][1] = true; // snake body
    int time = 0;

    while (1){
        time++;
            // stretch snake's body & move head next spot
            int next_dx = snake.front().first + dx[snake_dir];
            int next_dy = snake.front().second + dy[snake_dir];
            snake.push_front({next_dx, next_dy});

            // break
            if (next_dx == 0 || next_dy == 0 || next_dx > n || next_dy > n || chk[next_dx][next_dy]) break;

            if (board[next_dx][next_dy] == 1) { // apple O
                board[next_dx][next_dy] = 0; // eat
                chk[next_dx][next_dy] = true; // snake body
            }

            else { // apple X
                chk[snake.back().first][snake.back().second] = false; // no 
                snake.pop_back();
                chk[next_dx][next_dy] = true; // snake body
            }

        if (chg.find(time) != chg.end()){ // find change direction
            if (chg[time] == 'L'){ // left
                snake_dir--;
                if (snake_dir < 0) snake_dir = 3;
            }

            if (chg[time] == 'D'){ // right
                snake_dir++;
                if (snake_dir > 3) snake_dir = 0;
            } 
        }        
    }

    cout << time;

    return 0;
}