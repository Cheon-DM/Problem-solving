#include <iostream>
#include <vector>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

vector<int> list;
vector<int> asc_list = {1, 2, 3, 4, 5, 6, 7, 8};
vector<int> des_list = {8, 7, 6, 5, 4, 3, 2, 1};
int main(){
    fio;
    int a;
    for (int i = 0; i < 8; i++){
        cin >> a;
        list.push_back(a);
    }

    if (list == asc_list){
        cout << "ascending";
    }

    else if (list == des_list){
        cout << "descending";
    }

    else {
        cout << "mixed";
    }

}