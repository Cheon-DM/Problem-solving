/**
 * baekjoon - 4195
 * hashmap, union-find
 */

#include <iostream>
#include <map>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

map<string, int> list;
int parent[200001];
int friend_num[200001];

int find_parent(int x){
    if (parent[x] == x) return x;

    return parent[x] = find_parent(parent[x]);
}

void make_union(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if (a < b){
        parent[b] = a;
        friend_num[a] += friend_num[b];
    }

    else if (b < a){
        parent[a] = b;
        friend_num[b] += friend_num[a];
    }
}

int main(){
    fio;
    //input
    int testcase; cin >> testcase;
    string a, b;
    int n, cnt;

    for (int t = 0; t < testcase; t++){
        // clear
        cnt = 0;
        list.clear();
        for (int i = 0; i < 200001; i++){
            parent[i] = i;
            friend_num[i] = 1;
        }
        cin >> n;
        int x, y;
        for (int i = 0; i < n; i++){
            cin >> a >> b;

            if (list.find(a) == list.end()) {
                list[a] = ++cnt;
                x = cnt;
            }
            else {
                x = list.find(a)->second;
            }

            if (list.find(b) == list.end()) {
                list[b] = ++cnt;
                y = cnt;
            }
            else {
                y = list.find(b)->second;
            }

            make_union(x, y);

            int root = find_parent(x);
            cout << friend_num[root] << "\n";
        }
    }

    return 0;
}