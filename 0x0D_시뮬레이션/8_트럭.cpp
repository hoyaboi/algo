#include <bits/stdc++.h>
using namespace std;

int sum_bridge(deque<int>);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, l; cin >> n >> w >> l;
    vector<int> truck(n);
    deque<int> bridge;
    for(int& i : truck) cin >> i;
    for(int i = 0; i < w; i++) bridge.push_back(0);

    int cnt = 0;
    for(int i = 0; i < n;)  {
        if(sum_bridge(bridge) - bridge[0] + truck[i] > l) bridge.push_back(0);
        else bridge.push_back(truck[i++]);
        bridge.pop_front();
        cnt++;
    }
    cnt += w;
    cout << cnt;
}
int sum_bridge(deque<int> deq) {
    int sum = 0;
    for(int i = 0; i < deq.size(); i++) sum += deq[i];
    return sum;
}

// https://www.acmicpc.net/problem/13335