#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pque;
    while(n--) {
        int tmp; cin >> tmp;
        pque.push(tmp);
    }
    ll result = 0;
    while(pque.size() != 1) {
        ll a = pque.top(); pque.pop();
        ll b = pque.top(); pque.pop();
        result += a+b;
        pque.push(a+b);
    }
    cout << result;
}

// https://www.acmicpc.net/problem/1715