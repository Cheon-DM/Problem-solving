#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)

using namespace std;
using ll = long long;


ll fibo(long p, long q){
    vector<ll> fibodata(p+1, 0);
    fibodata[0] = 0;
    fibodata[1] = 1;
    fibodata[2] = 1;
    for (int i = 3; i <= p; i++){
        fibodata[i] = fibodata[i-1] + fibodata[i-2];
        fibodata[i] %= q; // overflow로 나머지를 저장해줌 ?
    }

    return fibodata[p] % q;
}

int main(){
    fio;

    int t;
    cin >> t; // testcase

    int p, q;
    long result;
    for (int i = 0; i < t; i++){
        cin >> p >> q;
        result = fibo(p, q);
        cout << "Case #" << i+1 << ": " << result << "\n";
    }
}

// dp