/**
 * baekjoon - 14502
 * graph, bruteforcing, bfs
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int N, M;
int arr[9][9];
int CopyArr[9][9];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int _max = 0;

void copy(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            CopyArr[i][j] = arr[i][j];
        }
    }
}

void bfs(){
    queue<pair<int, int>> q;
    vector<vector<bool>> checked;
    checked.assign(N, vector<bool>(M, false));


    // push virus
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (CopyArr[i][j] == 2) {
                q.push({i, j});
                checked[i][j] = true;
            }
        }
    }

    // bfs
    while(!q.empty()){
        pair<int, int> tmp = q.front(); q.pop();

        for (int i = 0; i < 4; i++){
            int nX = tmp.first + dx[i];
            int nY = tmp.second + dy[i];

            if (nX < 0 || nY < 0 || nX >= N || nY >= M || CopyArr[nX][nY] == 1) continue;

            if (!checked[nX][nY]){
                q.push({nX, nY});
                CopyArr[nX][nY] = 2;
                checked[nX][nY] = true;
            }

        }
    }
}

void calculateMaxArea(){
    int sum = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (CopyArr[i][j] == 0) sum++;
        }
    }
    if (_max < sum) _max = sum;
}

int main(){
    fio;
    //input
    vector<pair<int, int>> blank;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 0) blank.push_back({i, j});
        }
    }

    /**
     * 1. 벽 3개를 조합으로 뽑아 벽 지음
     * 2. bfs 이용해 바이러스 전파
     * 3. 안전 영역 세기
     **/
    //sol
    sort(blank.begin(), blank.end());
    vector<int> assist;
    assist.assign(blank.size()-3, 0);
    assist.push_back(1); assist.push_back(1); assist.push_back(1);

    do{
        // copy arr
        copy();

        // build 3 walls
        for (int i = 0; i < blank.size(); i++){
            if (assist[i] != 0) CopyArr[blank[i].first][blank[i].second] = 1;
        }

        //bfs
        bfs();

        //calculate max area
        calculateMaxArea();

    } while(next_permutation(assist.begin(), assist.end()));

    cout << _max;

    return 0;
}