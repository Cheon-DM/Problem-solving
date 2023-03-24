/**
 * baekjoon - 10845
 * queue
 */

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    //fio;
    //input
    queue<int> q;
    string str;
    int num;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;

        if (str == "push"){
            cin >> num;
            q.push(num);
        }
        if (str == "pop"){
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if (str == "size"){
            cout << q.size() << "\n";
        }
        if (str == "empty"){
            cout << q.empty() << "\n";
        }
        if (str == "front"){
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        if (str == "back"){
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}
