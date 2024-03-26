#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t; cin >> n;
    vector<pii> vec(n);
    for(auto& a : vec) cin >> t >> a.first >> a.second;
    sort(vec.begin(), vec.end());
    priority_queue<pii, vector<pii>, greater<pii>> pque;
    for(auto a : vec) {
        if(!pque.empty() && a.first >= pque.top().first) pque.pop();
        pque.push({a.second, a.first});
    }
    cout << pque.size();
}

// https://www.acmicpc.net/problem/1374