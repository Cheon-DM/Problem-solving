#include <iostream>
#include <string>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main(){
    fio;

    int t; cin >> t;

    for (int i = 0; i < t; i++){
        string s1;
        cin >> s1;

        int score = 0;
        int count = 0;
        for (int j = 0; j < s1.length(); j++){
            if (s1.at(j) == 'O') {
                count++;
                score += count;
            }

            else {
                count = 0;
            }
        }

        cout << score << "\n";
    }
}