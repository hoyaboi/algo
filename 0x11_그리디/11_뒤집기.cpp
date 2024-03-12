#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    char c = s[0];
    int cnt = 0;
    for(char next : s)
        if(c != next) {
            cnt++;
            c = next;
        }
    cout << (cnt+1)/2;
}

// https://www.acmicpc.net/problem/1439