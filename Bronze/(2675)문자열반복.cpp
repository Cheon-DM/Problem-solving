#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)

using namespace std;

int main(){
    fio;
    int t; cin >> t;

    int r;
    string s;
    for (int i = 0; i < t; i++){
        cin >> r >> s;
        
        for (int j = 0; j < s.length(); j++){
            int chk = 0;
            while(!(chk == r)){
                cout << s[j];
                chk++;
            }
        }
        cout << "\n";
    }
}