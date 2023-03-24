#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
using ll = long long;
vector<pair<ll, ll>> fibodata(41);

void fibo(int n){
    fibodata[0] = make_pair(1, 0);
    fibodata[1] = make_pair(0, 1);
    fibodata[2] = make_pair(1, 1);
    for (int i = 3; i <= n; i++){
        fibodata[i].first = fibodata[i-1].first + fibodata[i-2].first;
        fibodata[i].second = fibodata[i-1].second + fibodata[i-2].second;
    }

    return;
}

int main(){
    fio;
    
    int t; cin >> t;
    int n;
    for (int i = 0; i < t; i++){
        cin >> n;
        fibo(n);
        cout << fibodata[n].first << " " << fibodata[n].second << "\n";
    }

    return 0;

}