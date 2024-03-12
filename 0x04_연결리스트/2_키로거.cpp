#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<list<char>> pwd(n);
    list<char>::iterator it;

    for(int i = 0; i < n; i++) {
        it = pwd[i].begin();
        string tmp;
        cin >> tmp;
        for(char c : tmp) {
            switch (c) {
            case '<':
                if(it != pwd[i].begin()) it--;
                break;
            case '>':
                if(it != pwd[i].end()) it++;
                break;
            case '-':
                if(it != pwd[i].begin()) pwd[i].erase(prev(it));
                break;
            default:
                pwd[i].insert(it, c);
                break;
            }
        }
        for(char c : pwd[i]) cout << c;
        cout << "\n";
    }
}

// https://www.acmicpc.net/problem/5397