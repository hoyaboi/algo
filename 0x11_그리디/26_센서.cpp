#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k; cin >> n >> k;
    vector<int> vec(n);
    for(int& i : vec) cin >> i;
    sort(vec.begin(), vec.end());
    
    priority_queue<int, vector<int>> pque;
    for(int i = 1; i < n; i++) pque.push(vec[i] - vec[i-1]);
    for(int i = 0; !pque.empty() && i < k-1; i++) pque.pop();

    int sum = 0;
    while(!pque.empty()) {
        sum += pque.top();
        pque.pop();
    }
    cout << sum;
}

// https://www.acmicpc.net/problem/2212