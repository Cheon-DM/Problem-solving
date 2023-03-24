/**
 * baekjoon - 10816
 * hashmap? sorting
 */

#include <iostream>
#include <map>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

map<int, int> cardMap;

int main(){
    fio;
    //input
    int n; cin >> n;
    long long card;
    for (int i = 0; i < n; i++){
        cin >> card;
        if (cardMap.find(card) == cardMap.end()){ // not find
            cardMap[card] = 1;
        }
        else cardMap[card]++;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        cin >> card;
        cout << cardMap[card] << ' ';
    }
    

    return 0;
}