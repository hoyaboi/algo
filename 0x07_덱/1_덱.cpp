#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> deq;

    while(n--) {
        string com;
        cin >> com;
        if(com == "push_front") {
            int num;
            cin >> num;
            deq.push_front(num);
        } else if(com == "push_back") {
            int num;
            cin >> num;
            deq.push_back(num);
        } else if(com == "pop_front") {
            if(!deq.empty()) {
                cout << deq.front() << "\n";
                deq.pop_front();
            } else cout << -1 << "\n";
        } else if(com == "pop_back") {
            if(!deq.empty()) {
                cout << deq.back() << "\n";
                deq.pop_back();
            } else cout << -1 << "\n";
        } else if(com == "size") {
            cout << deq.size() << "\n";
        } else if(com == "empty") {
            if(deq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if(com == "front") {
            if(!deq.empty()) cout << deq.front() << "\n";
            else cout << -1 << "\n";
        } else if(com == "back") {
            if(!deq.empty()) cout << deq.back() << "\n";
            else cout << -1 << "\n";
        }
    }
}

// https://www.acmicpc.net/problem/10866