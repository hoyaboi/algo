#include <bits/stdc++.h>
using namespace std;

pair<int, int> D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> D[i].second >> D[i].first;
    sort(D, D + n);
    int cnt = 0, end_time = 0;
    for(int i = 0; i < n; i++) {
        if(D[i].second < end_time) continue;
        end_time = D[i].first;
        cnt++;
    }
    cout << cnt;
}

// https://www.acmicpc.net/problem/1931