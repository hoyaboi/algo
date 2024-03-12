#include <bits/stdc++.h>
using namespace std;
#define START first 
#define END second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> flower(n);

    for(auto& i : flower) {
        int s_m, s_d, e_m, e_d;
        cin >> s_m >> s_d >> e_m >> e_d;
        i = {s_m * 100 + s_d, e_m * 100 + e_d};
    }
    int now = 301, cnt = 0;
    while(now <= 1130) {
        int next = now;
        for(int i = 0; i < n; i++)
            if(flower[i].START <= now && flower[i].END > next)
                next = flower[i].END;
        if(next == now) {
            cout << 0;
            return 0;
        }
        cnt++;
        now = next;
    }
    cout << cnt;
}


// https://www.acmicpc.net/problem/2457