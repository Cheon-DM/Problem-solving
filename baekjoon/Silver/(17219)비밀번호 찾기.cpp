/**
 * baekjoon - 17219
 * hashmap
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // INPUT
    cin >> N >> M;

    string site, password;
    for (int i = 0; i < N; i++) {
        cin >> site >> password;
        m[site] = password;
    }

    for (int i = 0; i < M; i++) {
        cin >> site;
        cout << m[site] << '\n';
    }

    return 0;
}