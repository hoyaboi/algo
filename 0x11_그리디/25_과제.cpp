#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> vec(n);
    for(auto& a : vec) cin >> a.first >> a.second;
    sort(vec.rbegin(), vec.rend());

    priority_queue<int> pq;
    int sum = 0, j = 0;
    for(int i = 1000; i >= 1; i--) {
        while(j < n && vec[j].first >= i) {
            pq.push(vec[j].second);
            j++;
        }
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}

// https://www.acmicpc.net/problem/13904