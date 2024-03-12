#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> prque;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        prque.push(tmp);
    }
    for(int i = 0; i < m; i++) {
        ll a = prque.top(); prque.pop();
        ll b = prque.top(); prque.pop();
        prque.push(a+b);
        prque.push(a+b);
    }
    ll sum = 0;
    while(!prque.empty()) {
        sum += prque.top();
        prque.pop();
    }
    cout << sum;
}

// https://www.acmicpc.net/problem/15903