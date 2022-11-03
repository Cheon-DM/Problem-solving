/**
 * baekjoon - 14500
 * implementation, bruteforce
 */

#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/**
 * 5가지의 테트로미노의 모든 경우의 수를 저장하여,
 * 해당 종이 위에 모두 올려본 후,
 * 최대값을 구함
*/

int arr[500][500] = {0, };
int tetrominos[19][4][2] = {
	// 직사각형
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},

	// 정사각형
	{{0, 0}, {1, 0}, {0, 1}, {1, 1}},

	// ㄹ형
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},

	// ㅗ형
	{{0, 0}, {1, 0}, {2, 0}, {1, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},

	// ㄴ형
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 0}}
};

int main(){
    fio;
    //input
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    //sol
    int _max = 0;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            for (int i = 0; i < 19; i++) {
                int cX2 = x + tetrominos[i][1][0];
                int cY2 = y + tetrominos[i][1][1];
                int cX3 = x + tetrominos[i][2][0];
                int cY3 = y + tetrominos[i][2][1];
                int cX4 = x + tetrominos[i][3][0];
                int cY4 = y + tetrominos[i][3][1];

                if (cX2 < 0 || cX3 < 0 || cX4 < 0 || cY2 < 0 || cY3 < 0 || cY4 < 0 || cX2 >= N || cX3 >= N || cX4 >= N || cY2 >= M || cY3 >= M || cY4 >= M)
                    continue;

                int sum = arr[x][y] + arr[cX2][cY2] + arr[cX3][cY3] + arr[cX4][cY4];

                if (_max < sum)
                    _max = sum;
            }
        }
    }

    cout << _max;

    return 0;
}