#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    stack<int> stk;
    int sum = 0;

    while(k--) {
        int tmp;
        cin >> tmp;
        if(tmp != 0) {
            stk.push(tmp);
            sum += stk.top();
        }
        else {
            if(!stk.empty()) {
                sum -= stk.top();
                stk.pop();
            }
        }
    }
    cout << sum;
}

// https://www.acmicpc.net/problem/10773