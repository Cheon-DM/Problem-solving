/**
 * baekjoon - 12100
 * implementation, bruteforce, simulation, backtracking
 **/

#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n;
int _max = 0;

vector<vector<int>> move(vector<vector<int>> board, int type){
    pair<int, int> cur, next;

    vector<vector<int>> board_R;
    board_R.assign(n, vector<int>(n, 0));

    if (type == 2 || type == 3){
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++){
                board_R[j][i] = board[i][j];
            }
        }        
    }

    if (type == 0){ // left
        for (int i = 0; i < n; i++){
            cur = make_pair(i, 0);
            int zeroChk = 0;
            for (int j = 1; j < n; j++){
                
                next = make_pair(i, j);

                if (board[cur.first][cur.second] == 0) {
                    if (zeroChk == n -1) break;
                    board[i].erase(board[i].begin() + cur.second);
                    board[i].push_back(0);
                    j--;
                    zeroChk++;
                    continue;
                }

                if (board[next.first][next.second] == 0){
                    if (zeroChk == n -1) break;
                    board[i].erase(board[i].begin() + next.second);
                    board[i].push_back(0);
                    j--;
                    zeroChk++;
                    continue;
                }

                if (board[cur.first][cur.second] == board[next.first][next.second]) {
                    board[cur.first][cur.second] *= 2;
                    cur = make_pair(next.first, next.second);
                    board[i].erase(board[i].begin() + next.second);
                    board[i].push_back(0);
                }

                else {
                    cur = next;
                }
            }
        }
    }

    else if (type == 1){ // right
        for (int i = 0; i < n; i++){
            cur = make_pair(i, n - 1);
            int zeroChk = 0;
            for (int j = n - 2; j >= 0; j--){
                next = make_pair(i, j);

                if (board[cur.first][cur.second] == 0) {
                    if (zeroChk == n -1) break;
                    board[i].erase(board[i].begin() + cur.second);
                    board[i].insert(board[i].begin(), 0);
                    j++;
                    zeroChk++;
                    continue;
                }

                if (board[next.first][next.second] == 0) {
                    if (zeroChk == n -1) break;
                    board[i].erase(board[i].begin() + next.second);
                    board[i].insert(board[i].begin(), 0);
                    j++;
                    zeroChk++;
                    continue;
                }

                if (board[cur.first][cur.second] == board[next.first][next.second]) {
                    board[cur.first][cur.second] *= 2;
                    cur = make_pair(next.first, next.second);
                    board[i].erase(board[i].begin() + next.second);
                    board[i].insert(board[i].begin(), 0);
                }

                else {
                    cur = next;
                }
            }

        }
    }

    else if (type == 2){ // up
        for (int i = 0; i < n; i++){
            cur = make_pair(i, 0);
            int zeroChk = 0;
            for (int j = 1; j < n; j++){

                next = make_pair(i, j);
                if (board_R[cur.first][cur.second] == 0) {
                    if (zeroChk == n -1) break;
                    board_R[i].erase(board_R[i].begin() + cur.second);
                    board_R[i].push_back(0);
                    j--;
                    zeroChk++;
                    continue;
                }

                if (board_R[next.first][next.second] == 0) {
                    if (zeroChk == n -1) break;
                    board_R[i].erase(board_R[i].begin() + next.second);
                    board_R[i].push_back(0);
                    j--;
                    zeroChk++;
                    continue;
                }

                if (board_R[cur.first][cur.second] == board_R[next.first][next.second]) {
                    board_R[cur.first][cur.second] *= 2;
                    cur = make_pair(next.first, next.second);
                    board_R[i].erase(board_R[i].begin() + next.second);
                    board_R[i].push_back(0);
                }

                else {
                    cur = next;
                }
            }

        }
    }

    else if (type == 3){ // down
        for (int i = 0; i < n; i++){
            cur = make_pair(i, n-1);
            int zeroChk = 0;
            for (int j = n-2; j >= 0; j--){

                next = make_pair(i, j);
                if (board_R[cur.first][cur.second] == 0) {
                    if (zeroChk == n -1) break;
                    board_R[i].erase(board_R[i].begin() + cur.second);
                    board_R[i].insert(board_R[i].begin(), 0);
                    j++;
                    zeroChk++;
                    continue;
                }

                if (board_R[next.first][next.second] == 0) {
                    if (zeroChk == n -1) break;
                    board_R[i].erase(board_R[i].begin() + next.second);
                    board_R[i].insert(board_R[i].begin(), 0);
                    j++;
                    zeroChk++;
                    continue;
                }

                if (board_R[cur.first][cur.second] == board_R[next.first][next.second]) {
                    board_R[cur.first][cur.second] *= 2;
                    cur = make_pair(next.first, next.second);
                    board_R[i].erase(board_R[i].begin() + next.second);
                    board_R[i].insert(board_R[i].begin(), 0);
                }

                else {
                    cur = next;
                }
            }

        }
    }

    if (type == 2 || type == 3){
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++){
                board[i][j] = board_R[j][i];
            }
        }        
    }
    
    return board;
}

void dfs(int cnt, vector<vector<int>> board){
    if (cnt == 5){ // find max
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (_max < board[i][j]) _max = board[i][j];
            }
        }
    }

    else {
        dfs(cnt+1, move(board, 0));
        dfs(cnt+1, move(board, 1));
        dfs(cnt+1, move(board, 2));
        dfs(cnt+1, move(board, 3));
    }
}

int main(){
    fio;

    //input
    cin >> n;
    vector<vector<int>> board;
    board.assign(n,  vector<int>(n, 0));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    //sol
    dfs(0, board);
    
    cout << _max;

    return 0;
}