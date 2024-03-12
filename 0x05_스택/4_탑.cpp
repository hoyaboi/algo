#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> stk;

    for(int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        while(!stk.empty() && stk.top().first < height)
            stk.pop();
        if(stk.empty()) cout << 0 << " ";
        else cout << stk.top().second << " ";
        auto tmp = make_pair(height, i);
        stk.push(tmp);
    }
}

// https://www.acmicpc.net/problem/2493