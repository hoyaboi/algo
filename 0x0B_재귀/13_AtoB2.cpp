#include <bits/stdc++.h>
using namespace std;

bool back(string t, string s) {
    if(t == s) return 1;
    if(t.size() < s.size()) return 0;

    bool res = 0;
    if(t.back() == 'A') {
        t.pop_back();
        res = back(t, s);
        t.push_back('A');
    }
    if(!res && t.front() == 'B') {
        reverse(t.begin(), t.end());
        t.pop_back();
        res = back(t, s);
        t.push_back('B');
        reverse(t.begin(), t.end());
    }
    return res;
}
int main() {
    string s, t;
    cin >> s >> t;
    cout << back(t, s) << '\n';
    return 0;
}

// https://www.acmicpc.net/problem/12919