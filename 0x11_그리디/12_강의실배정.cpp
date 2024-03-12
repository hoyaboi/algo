#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> class_time[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> class_time[i].first >> class_time[i].second;
    sort(class_time, class_time + n);

    priority_queue<ll, vector<ll>, greater<ll>> end_time;
    int cnt = 1;
    end_time.push(class_time[0].second);
    for(int i = 1; i < n; i++) {
        if(class_time[i].first < end_time.top()) cnt++;
        else end_time.pop();
        end_time.push(class_time[i].second);
    }
    cout << cnt;
}

// https://www.acmicpc.net/problem/11000