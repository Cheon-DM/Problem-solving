#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    int n; cin >> n;
    double score[n];
    double trans_score[n] = {0, };
    double _max = 0;
    double total = 0;

    for (int i = 0; i < n; i++){
        cin >> score[i];
        if (_max < score[i]){
            _max = score[i];
        }
    }

    for (int i = 0; i < n; i++){
        trans_score[i] = score[i] / _max * 100;
        total += trans_score[i];
    }

    cout << total / n;


    return 0;
}