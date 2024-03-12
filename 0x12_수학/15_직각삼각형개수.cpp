#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;

int n, cnt;
vector<pair<ll, ll>> point;

ll length(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        point.push_back({x, y});
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                ll line0 = length(i, j);
                ll line1 = length(j, k);
                ll line2 = length(k, i);
                if(line0 < line1) swap(line0, line1);
                if(line0 < line2) swap(line0, line2);
                if(line0 == line1 + line2) cnt++;
            }
        }
    }
    cout << cnt;
}   
ll length(int a, int b) {
    ll sq = 0;
    ll tmp = abs(point[a].X-point[b].X);
    sq += tmp * tmp;
    tmp = abs(point[a].Y-point[b].Y);
    return sq += tmp * tmp;
}

// https://www.acmicpc.net/problem/1711