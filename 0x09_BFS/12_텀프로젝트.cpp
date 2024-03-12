#include <bits/stdc++.h>
using namespace std;

int n, arr[100002], team[100002];

void cycle(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        fill(team, team + n+1, false);
        for(int i = 1; i <= n; i++) cin >> arr[i];
        for(int i = 1; i <= n; i++) if(!team[i]) cycle(i);

        int cnt = 0;
        for(int i = 1; i <= n; i++) if(team[i] != -1) cnt++;
        cout << cnt << "\n";
    }
}
void cycle(int k) {
    int cur = k;
    while(1) {
        team[cur] = k;
        cur = arr[cur];
        if(team[cur] == k) {
            while(team[cur] != -1) {
                team[cur] = -1;
                cur = arr[cur];
            }
            return;
        }
        else if(team[cur]) return;
    }
}

// https://www.acmicpc.net/problem/9466