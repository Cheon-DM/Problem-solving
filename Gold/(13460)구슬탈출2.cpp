/**
 * baekjoon - 13460
 * graph, bfs, simulation
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr) 
using namespace std;

char board[11][11];
bool chk[11][11][11][11] = {false, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    fio;
    //input
    int n, m; cin >> n >> m;
    int answer;
    pair<int, int> red, blue, hole;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                red = make_pair(i, j);
                board[i][j] = '.';
            }

            else if (board[i][j] == 'B') {
                blue = make_pair(i, j);
                board[i][j] = '.';
            }

            else if (board[i][j] == 'O') {
                hole = make_pair(i, j);
            }
        }
    }

    //sol
    queue<tuple<int, int, int, int, int>> q;
    q.push({red.first, red.second, blue.first, blue.second, 0});
    int cnt;
    int flag = 0;

    while (!q.empty()){
        // current red and blue location
        int cur_Rx = get<0>(q.front());
        int cur_Ry = get<1>(q.front());
        int cur_Bx = get<2>(q.front());
        int cur_By = get<3>(q.front());
        cnt = get<4>(q.front());
        q.pop();

        // checking visited
        chk[cur_Rx][cur_Ry][cur_Bx][cur_By] = true;

        // cnt > 10
        if(cnt > 10) break;

        // find hole
        if (cur_Rx == hole.first && cur_Ry == hole.second) {
            flag = 1;
            answer = cnt;
            break;
        }

        //bfs
        for (int i = 0; i < 4; i++){
            int next_Rx = cur_Rx;
            int next_Ry = cur_Ry;
            int next_Bx = cur_Bx;
            int next_By = cur_By;

            while(1) { // move R
                if (board[next_Rx + dx[i]][next_Ry + dy[i]] == '.'){ // road
                    next_Rx += dx[i];
                    next_Ry += dy[i];
                }

                else if (board[next_Rx + dx[i]][next_Ry + dy[i]] == 'O'){ // hole
                    next_Rx += dx[i];
                    next_Ry += dy[i];
                    break;
                }

                else break; // wall
            }

            while(1) { // move B
                if (board[next_Bx + dx[i]][next_By + dy[i]] == '.'){ // road
                    next_Bx += dx[i];
                    next_By += dy[i];
                }

                else if (board[next_Bx + dx[i]][next_By + dy[i]] == 'O'){ // hole
                    next_Bx += dx[i];
                    next_By += dy[i];
                    break;
                }
                
                else break; // wall
            }

            // blue in the hole
            if (board[next_Bx][next_By] == 'O') continue;

            // overlap
            if (next_Rx == next_Bx && next_Ry == next_By){
                switch (i)
                {
                case 0:
                    cur_Rx > cur_Bx ? next_Rx++ : next_Bx++;
                    break;
                case 1:
                    cur_Rx < cur_Bx ? next_Rx-- : next_Bx--;
                    break;
                case 2:
                    cur_Ry > cur_By ? next_Ry++ : next_By++;
                    break;
                case 3:
                    cur_Ry < cur_By ? next_Ry-- : next_By--;
                    break;
                }
            }

            // not visited
            if (!chk[next_Rx][next_Ry][next_Bx][next_By]){
                q.push({next_Rx, next_Ry, next_Bx, next_By, cnt + 1});
            }
        }
    }

    //output
    if (flag == 1) cout << answer;
    else cout << "-1";

    return 0;
}