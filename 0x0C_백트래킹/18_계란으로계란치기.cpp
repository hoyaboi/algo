#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> eggs;
int n, cnt;

void func(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int dur, wgt; cin >> dur >> wgt;
        eggs.push_back({dur, wgt});
    }
    func(0);
    cout << cnt;
}
void func(int k) {
    if(k == n) {
        int tmp = 0;
        for(auto i : eggs)
            if(i.first <= 0) tmp++;
        cnt = max(cnt, tmp);
        return;
    }
    if(eggs[k].first <= 0) func(k+1);
    else {
        for(int i = 0; i < n; i++) {
            if(i == k) continue;
            if(eggs[i].first > 0) {
                eggs[k].first -= eggs[i].second;
                eggs[i].first -= eggs[k].second;
                func(k+1);
                eggs[k].first += eggs[i].second;
                eggs[i].first += eggs[k].second;
            }
            else func(k+1);
        }
    }
}

// https://www.acmicpc.net/problem/16987