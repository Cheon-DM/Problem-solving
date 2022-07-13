#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main(){
    fio;

    int n; cin >> n;
    int num[n];
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    cout << num[0] << " " << num[n-1];
}