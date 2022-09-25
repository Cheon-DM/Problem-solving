/**
 * baekjoon - 5052
 * data structure, string, sorting, tree, trie
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

vector<string> teleNum;

int main(){
    fio;
    int t; cin >> t; //testcase

    for (int i = 0; i < t; i++){
        //input
        int n; cin >> n; //n개 전화번호
        string tel;
        for (int j = 0; j < n; j++){
            cin >> tel;
            teleNum.push_back(tel);
        }

        // sorting
        sort(teleNum.begin(), teleNum.end());

        // sol
        bool chk = false;
        for (int a = 0; a < teleNum.size()-1; a++){
            string tmp = teleNum[a];

            if (tmp.length() >= teleNum[a+1].length()) continue;

            string slice = teleNum[a+1].substr(0, tmp.length());
            if (strcmp(tmp.c_str(), slice.c_str()) == 0){
                cout << "NO\n";
                chk = true;
                break;
            }
        }
        if (chk == false) {
            cout << "YES\n";
        }

        teleNum.clear();
    }

    return 0;
}