#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> que;

    while(n--) {
        string com;
        cin >> com;
        if(com == "push") {
            int tmp;
            cin >> tmp;
            que.push(tmp);
        } else if(com == "pop") {
            if(!que.empty()) {
                cout << que.front() << "\n";
                que.pop();
            } else cout << -1 << "\n";
        } else if(com == "size") {
            cout << que.size() << "\n";
        } else if(com == "empty") {
            que.empty() ? cout << 1 : cout << 0;
            cout << "\n";
        } else if(com == "front") {
            que.empty() ? cout << -1 : cout << que.front();
            cout << "\n";
        } else {
            que.empty() ? cout << -1 : cout << que.back();
            cout << "\n";
        }
    }
}

// https://www.acmicpc.net/problem/18258