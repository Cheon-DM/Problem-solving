#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

queue<pair<int, int>> q;
queue<pair<int, int>> tmp;

int main(){
    //input
    fio;
    int m, n; cin >> m >> n;
    int tomato[n+2][m+2];
    memset(tomato, -1, sizeof(tomato));

    int no_tomato_num = 0;
    int tomato_num = 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> tomato[i][j];

            if (tomato[i][j] == 1) { // 익음
                q.push(make_pair(i, j));
                tomato_num++;
            }

            if (tomato[i][j] == -1) { // 토마토 없음
                no_tomato_num++;
            }
        }
    }

    //solution
    int date = 0;
    
    if (no_tomato_num == (n * m)) { // 모두 토마토 아님
        cout << -1;
    }

    else if ((tomato_num + no_tomato_num) == (n * m)){ // 익은 토마토만 있음
        cout << 0;
    }

    else
    {
        while (!q.empty())
        {
            tmp = q;
            q = queue<pair<int, int>>(); // 다음 단계를 위해 비움.

            while (!tmp.empty())
            {
                int tmp_i = tmp.front().first;
                int tmp_j = tmp.front().second;
                tmp.pop();

                if (tomato[tmp_i - 1][tmp_j] == 0)
                {
                    q.push(make_pair(tmp_i - 1, tmp_j));
                    tomato[tmp_i - 1][tmp_j] = 1;
                    tomato_num++;
                }

                if (tomato[tmp_i + 1][tmp_j] == 0)
                {
                    q.push(make_pair(tmp_i + 1, tmp_j));
                    tomato[tmp_i + 1][tmp_j] = 1;
                    tomato_num++;
                }

                if (tomato[tmp_i][tmp_j - 1] == 0)
                {
                    q.push(make_pair(tmp_i, tmp_j - 1));
                    tomato[tmp_i][tmp_j - 1] = 1;
                    tomato_num++;
                }

                if (tomato[tmp_i][tmp_j + 1] == 0)
                {
                    q.push(make_pair(tmp_i, tmp_j + 1));
                    tomato[tmp_i][tmp_j + 1] = 1;
                    tomato_num++;
                }
            }

            date++;
        }

        if (tomato_num + no_tomato_num == n * m)
            cout << date - 1;
        else
            cout << -1;
    }

    return 0;    
}