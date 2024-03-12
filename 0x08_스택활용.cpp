#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while(1) {
        bool isBalaced = true;
        stack<char> stk;

        getline(cin, str);
        if(str == ".") break;

        for(char c : str) {
            if(c == '(' || c == '[') stk.push(c);
            else if(c == ')') {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else {
                    isBalaced = false;
                    break;
                }
            }
            else if(c == ']') {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else {
                    isBalaced = false;
                    break;
                }
            }
        }
        if(!stk.empty()) isBalaced = false;
        if(isBalaced) cout << "yes\n";
        else cout << "no\n";
    }
}
