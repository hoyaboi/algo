#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    priority_queue<pl, vector<pl>, greater<pl>> prque;
    while(n--) {
        ll a, b; cin >> a >> b;
        prque.push({a, b});
    }
    deque<pl> line;
    line.push_back(prque.top()); prque.pop();
    while(!prque.empty()) {
        pl cur = prque.top(); prque.pop();
        if(cur.first > line.back().second)
            line.push_back(cur);
        else if(cur.second > line.back().second) {
            pl tmp = line.back(); line.pop_back();
            line.push_back({tmp.first, cur.second});
        }
    }
    ll length = 0;
    while(!line.empty()) {
        pl tmp = line.front(); line.pop_front();
        length += tmp.second - tmp.first;
        cout << "(" << tmp.first << "," << tmp.second << ")" << " ";
    }
    cout << length;
}

// https://www.acmicpc.net/problem/2170