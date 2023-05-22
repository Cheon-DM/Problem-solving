/**
 * SW Expert Academy - 1215
 *
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int t = 1; t <= 10; t++) {
        int n;
        string board[8];
        string rev_board[8];

        cin >> n;

        for (int i = 0; i < 8; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < 8; i++) {
            string s = "";
            for (int j = 0; j < 8; j++) {
                s += board[j][i];
            }
            rev_board[i] = s;
        }

        int cnt = 0;

        // 가로
        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8 - n + 1; k++) {
                string str = board[i].substr(k, n);
                string pal = "";

                for (int idx = str.size() - 1; idx >= 0; idx--) {
                    pal += str[idx];
                }

                if (str == pal) {
                    cnt++;
                }
            }
        }

        // 세로
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8 - n + 1; k++) {
                string str = rev_board[j].substr(k, n);
                string pal = "";

                for (int idx = str.size() - 1; idx >= 0; idx--) {
                    pal += str[idx];
                }

                if (str == pal) {
                    cnt++;
                }
            }
        }

        cout << "#" << t << " " << cnt << endl;
    }

    return 0;
}