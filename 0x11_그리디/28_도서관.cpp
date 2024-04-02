#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<int> left, right;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp > 0) right.push_back(tmp);
        else left.push_back(-tmp);
    }
    sort(left.rbegin(), left.rend());
    sort(right.rbegin(), right.rend());
    
    int ans = 0;
    for(int i = 0; i < left.size(); i += m) ans += left[i]*2;
    for(int i = 0; i < right.size(); i += m) ans += right[i]*2;

    int maxDist = 0;
    if (!left.empty() && !right.empty()) maxDist = max(left[0], right[0]);
    else if (!left.empty()) maxDist = left[0];
    else if (!right.empty()) maxDist = right[0];
    ans -= maxDist;

    cout << ans;
}

// https://www.acmicpc.net/problem/1461