/* backtracking */

#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int l, c, x, y;
char alphabet[15];
int vowel; // 모음
int consonant; // 자음
bool chk[15] = {false, };
char result[15];

void backtracking(int num, int tmp){
    if (num == l){
        vowel = 0;
        consonant = 0;

        for (int i = 0; i < l; i++){
            if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') vowel++;
            else consonant++;
        }

        if (vowel >= 1 && consonant >= 2){
            for (int i = 0; i < l; i++){
                cout << result[i];
            }
            cout << "\n";                
        }
        return;
    }

    for (int i = tmp; i < c; i++){
        if (!chk[i]){
            chk[i] = true;
            result[num] = alphabet[i];            
            backtracking(num+1, i+1);
            chk[i] = false;
        }
    }
}

int main(){
    //input
    fio;
    x = 0;
    y = 0;
    cin >> l >> c;
    for (int i = 0; i < c; i++){
        cin >> alphabet[i];
    }

    sort(alphabet, alphabet + c);

    //sol
    backtracking(0, 0);

    return 0;
}