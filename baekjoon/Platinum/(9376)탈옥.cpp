/**
 * baekjoon - 9376
 *
 */

/* 이런 형태로 prison 구성
........
.******.
.*    *.
.******.
........
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 9876543
using namespace std;

struct Node
{
    int x, y;
    int cost;
};

struct compare
{
    bool operator()(Node &n1, Node &n2)
    {
        return n1.cost > n2.cost;
    }
};

int T, H, W;
char prison[102][102];
pair<int, int> prisoner[2]; // 2명의 죄수
int door[3][102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dijkstra(int personIndex, int x, int y)
{
    priority_queue<Node, vector<Node>, compare> pq;
    pq.push({x, y, 0});
    door[personIndex][x][y] = 0;

    while (!pq.empty())
    {
        int cx = pq.top().x;
        int cy = pq.top().y;
        int cost = pq.top().cost;
        pq.pop();

        // 이미 저장된 비용이 현재 비용보다 작은 경우 pass
        if (door[personIndex][cx][cy] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx > H + 1 || ny > W + 1)
                continue;

            int nCost = cost;

            if (prison[nx][ny] == '*') // 벽
                continue;
            else if (prison[nx][ny] == '#') // 문 -> cost증가
                nCost++;

            // 다음 cost가 현재 저장된 cost보다 작은 경우
            if (nCost < door[personIndex][nx][ny])
            {
                pq.push({nx, ny, nCost});
                door[personIndex][nx][ny] = nCost;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> H >> W;
        string str;
        int idx = 0;
        for (int i = 1; i <= H; i++)
        {
            cin >> str;
            str = '.' + str + '.';
            for (int j = 0; j <= W + 1; j++)
            {
                prison[i][j] = str[j];

                if (prison[i][j] == '$')
                {
                    prisoner[idx++] = {i, j};
                }
            }
        }

        for (int j = 0; j <= W + 1; j++)
        {
            prison[0][j] = '.';
            prison[H + 1][j] = '.';
        }

        // init
        fill_n(&door[0][0][0], 3 * 102 * 102, MAX);

        // dijkstra
        dijkstra(0, 0, 0); // 상근 (0, 0)에서 출발
        dijkstra(1, prisoner[0].first, prisoner[0].second);
        dijkstra(2, prisoner[1].first, prisoner[1].second);

        int ans = MAX;
        for (int i = 0; i <= H + 1; i++)
        {
            for (int j = 0; j <= W + 1; j++)
            {
                if (prison[i][j] == '*')
                    continue;

                int openDoor = door[0][i][j] + door[1][i][j] + door[2][i][j];

                // 문인 경우 한 번만 열면 되므로 -2
                if (prison[i][j] == '#')
                {
                    openDoor -= 2;
                }

                ans = min(ans, openDoor);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}