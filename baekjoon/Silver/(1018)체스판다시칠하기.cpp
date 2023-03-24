#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string board[50];

int bw_count(int n, int m){
    int k =0;
    for (int i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            if (bw[i][j] != board[n+i][m+j]){
                k++;
            }
        }
    }
    return k;
}

int wb_count(int n, int m){
    int k =0;
    for (int i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            if (wb[i][j] != board[n+i][m+j]){
                k++;
            }
        }
    }
    return k;
}

int compare(int n, int m){
    int tmp;
    int minimun = 10000;
    for(int i = 0; i < n-7; i++){
        for(int j = 0; j < m-7; j++){
            tmp = min(bw_count(i, j), wb_count(i, j));
            if (minimun > tmp){
                minimun = tmp;
            }
        }
    }
    return minimun;
}

int main(){
    int n,m;
    cin >> n >> m;

    for (int i =0; i < n; i++){
        cin >> board[i];
    }

    cout << compare(n, m);

}
