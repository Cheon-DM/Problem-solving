/* backtracking */

#include <iostream>
#include <queue>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n;
int cnt = 0;
bool chk[101][101] = {false, };
char img[101][101] = {0, };
pair<int, int> around[4];

void fillAround(int i, int j){
    around[0] = make_pair(i-1, j); // 상
    around[1] = make_pair(i+1, j); // 하
    around[2] = make_pair(i, j-1); // 좌
    around[3] = make_pair(i, j+1); // 우
}

void bfs(int i, int j){

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    chk[i][j] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        fillAround(cur.first, cur.second);

        for (int a = 0; a < 4; a++)
        {
            pair<int, int> tmp = around[a];
            if (img[tmp.first][tmp.second] == img[cur.first][cur.second] && chk[tmp.first][tmp.second] == false)
            {
                chk[tmp.first][tmp.second] = true;
                q.push(tmp);
            }
        }
    }
}


int main(){
    //input
    fio;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> img[i][j];
    }

    // 적록색약 아닌사람
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (chk[i][j] == false) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt <<" ";

    // 적록색약인 사람
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (img[i][j] == 'G') img[i][j] = 'R';
            chk[i][j] = 0;
        }
    }
    cnt = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (chk[i][j] == false) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}