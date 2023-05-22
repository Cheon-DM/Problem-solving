/**
 * baekjoon - 1541
 * math, string, greedy, parsing
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<int> num;
    vector<char> oper;
    int p = 0;
    string sb = "";
    while (1) {
        if (p == str.length()) {
            num.push_back(stoi(sb));
            break;
        }

        if (str[p] == '+' || str[p] == '-') {
            oper.push_back(str[p]);

            if (sb.length() != 0) {
                num.push_back(stoi(sb));
                sb = "";
            }
        }

        else {
            sb += str.substr(p, 1);
        }

        p++;
    }

    // + operation
    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == '+') {
            num[i + 1] = num[i] + num[i + 1];
            num.erase(num.begin() + i);
            oper.erase(oper.begin() + i);
            i--;
        }
    }

    // - operation
    int ans = num[0];
    for (int i = 1; i < num.size(); i++) {
        ans -= num[i];
    }

    cout << ans << '\n';

    return 0;
}