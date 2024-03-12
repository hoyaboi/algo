#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    stack<char> stk;
    int count = 0;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ')' && str[i-1] == '(') {
            stk.pop();
            count += stk.size();
        } else if(str[i] == ')') {
            stk.pop();
            count++;
        } else stk.push(str[i]);
    }
    cout << count;
}

// https://www.acmicpc.net/problem/10799