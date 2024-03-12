#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<ll, ll>> point(n);
    for(auto& i : point) cin >> i.first >> i.second;
    ll tmp = 0;
    for(int i = 0; i < n; i++)
        tmp += point[i].first * point[(i+1)%n].second - point[(i+1)%n].first * point[i].second;
    double area = abs(tmp) / 2.0;
    cout << fixed << setprecision(1) << area;
}

// https://www.acmicpc.net/problem/2166