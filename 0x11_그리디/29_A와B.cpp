#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s, t; cin >> s >> t;
    while(s.size() != t.size()) {
        if(t.back() == 'A') t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        if(s == t) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

// https://www.acmicpc.net/problem/12904