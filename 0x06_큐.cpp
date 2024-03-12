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
            int num;
            cin >> num;
            que.push(num);
        } else if(com == "pop") {
            if(!que.empty()) {
                cout << que.front() << "\n";
                que.pop();
            } else cout << -1 << "\n";
        } else if(com == "size") {
            cout << que.size() << "\n";
        } else if(com == "empty") {
            if(que.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if(com == "front") {
            if(!que.empty()) cout << que.front() << "\n";
            else cout << -1 << "\n";
        } else if(com == "back") {
            if(!que.empty()) cout << que.back() << "\n";
            else cout << -1 << "\n";
        }
    }
}