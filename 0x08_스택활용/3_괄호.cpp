#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;
        stack<char> stk;
        bool isValid = true;
        
        for(char c : str) {
            if(c == '(') stk.push(c);
            else if(!stk.empty() && c == ')' && stk.top() == '(') stk.pop();
            else isValid = false;
        }
        if(!stk.empty()) isValid = false;

        if(isValid) cout << "YES\n";
        else cout << "NO\n";
    }
}

// https://www.acmicpc.net/problem/9012