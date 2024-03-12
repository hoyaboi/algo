#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    stack<char> stk;
    int mul = 1, sum = 0;
    bool isValid = true;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            stk.push(str[i]);
            mul *= 2;
        } else if(str[i] == '[') {
            stk.push(str[i]);
            mul *= 3;
        } else if(!stk.empty() && str[i] == ')' && stk.top() == '(') {
            if(str[i-1] == '(') sum += mul;
            stk.pop();
            mul /= 2;
        } else if(!stk.empty() && str[i] == ']' && stk.top() == '[') {
            if(str[i-1] == '[') sum += mul;
            stk.pop();
            mul /= 3;
        } else {
            isValid = false;
            break;
        }
    }
    if(!stk.empty()) isValid = false;

    if(isValid) cout << sum;
    else cout << 0;
}

// https://www.acmicpc.net/problem/2504