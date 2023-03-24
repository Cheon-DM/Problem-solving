#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main(){
    vector<pair<int, int>> v1;
    int a;
    for (int i = 1; i <= 9; i++){
        cin >> a;
        v1.push_back(make_pair(a, i));
    }

    sort(v1.begin(), v1.end(), greater<>());

    cout << v1.front().first << "\n" << v1.front().second;
}