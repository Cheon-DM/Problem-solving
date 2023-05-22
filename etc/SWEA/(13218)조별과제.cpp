/**
 * SW Expert Academy - 13218
 * math
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        cout << "#" << t << " " << (N / 3) << endl;
    }

    return 0;
}