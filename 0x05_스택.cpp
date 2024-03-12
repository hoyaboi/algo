#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> stk;

    while(n--) {
        string command;
        cin >> command;
        if(command == "push") {
            int num;
            cin >> num;
            stk.push(num);
        } else if(command == "pop") {
            if(!stk.empty()) {
                cout << stk.top() << "\n";
                stk.pop();
            } else cout << "-1\n";
        } else if(command == "size") {
            cout << stk.size() << "\n";
        } else if(command == "empty") {
            if(stk.empty()) cout << "1\n";
            else cout << "0\n";
        } else if(command == "top") {
            if(!stk.empty()) cout << stk.top() << "\n";
            else cout << "-1\n";
        }
    }
}
