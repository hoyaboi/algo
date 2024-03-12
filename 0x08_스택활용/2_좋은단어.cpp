#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count = 0;
    cin >> n;

    while(n--) {
        stack<char> stk;
        string str;
        cin >> str;

        for(char c : str) {
            if(!stk.empty() && stk.top() == c) stk.pop();
            else stk.push(c);
        }
        if(stk.empty()) count++;
    }
    cout << count;
}

// https://www.acmicpc.net/problem/3986