#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n), ans(n, -1);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        while(!stk.empty() && arr[i] > arr[stk.top()]) {
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i : ans) cout << i << " ";
}

// https://www.acmicpc.net/problem/17298