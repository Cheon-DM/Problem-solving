#include <iostream>
#include <set>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

set<string, greater<string>> person;

int main(){
    fio;
    int n; cin >> n;

    string name, state;
    int index = 0;

    for (int i = 0; i < n; i++){
        cin >> name >> state;

        if (state == "enter") {
            person.insert(name);
        }

        if (person.find(name) != person.end() && state == "leave"){
            person.erase(name);
        }
    }
    set<string>::iterator it;

    for (it = person.begin(); it != person.end(); it++){
        cout << *it << "\n";
    }
}