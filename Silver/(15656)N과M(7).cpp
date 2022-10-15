#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[9];
int result[9] = {0, };

void sol(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        result[level] = num[i];
        sol(level + 1);
            
    }
}

int main() {
    //input
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n);
    
    //sol
    sol(0);

    return 0;
}