#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> height(n), count(n);
    stack<int> stk;
    long long sum = 0;

    for(int i = 0; i < n; i++) cin >> height[i];
    for(int i = n-1; i >= 0; i--) {
        while(!stk.empty() && height[i] > height[stk.top()]) {
            count[i] += count[stk.top()] + 1;
            stk.pop();
        }
        stk.push(i);
    }
    for(int i : count) sum += i;
    cout << sum;
}

// https://www.acmicpc.net/problem/6198