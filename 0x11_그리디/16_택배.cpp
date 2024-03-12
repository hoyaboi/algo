#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> box;
int t[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, m; cin >> n >> c >> m;
    for(int i = 0; i < m; i++) {
        int s, r, w; cin >> s >> r >> w;
        box.push_back({r, s, w});
    }
    sort(box.begin(), box.end());
    int cnt = 0;
    for(auto a : box) {
        auto [receiver, sender, weight] = a;
        int max_truck = *max_element(t + sender, t + receiver);
        int capacity = min(weight, c - max_truck);
        for(int i = sender; i < receiver; i++) t[i] += capacity;
        cnt += capacity;
    }
    cout << cnt;
}

// https://www.acmicpc.net/problem/8980