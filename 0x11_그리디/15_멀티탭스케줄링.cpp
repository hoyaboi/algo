#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> vec(k);
    for(int& i : vec) cin >> i;
    vector<pair<int, int>> target(n);
    for(int i = 0, j = 0; j < n; i++) {
        bool isUsed = false;
        for(auto a : target)
            if(a.second == vec[i]) isUsed = true;
        if(isUsed) continue;
        target[j].first = k;
        target[j++].second = vec[i];
    }
    int length = 0;
    for(int i = n; i < k; i++) {
        for(auto& a : target)
            for(int j = i; j < k; j++)
                if(a.second == vec[j]) {
                    a.first = j;
                    break;
                }
        sort(target.begin(), target.end());
        if(target[0].second == vec[i]) {
            target[0].first = k;
            continue;
        }
        target[n-1].second = vec[i];
        target[n-1].first = k;
        length++;
    }
    cout << length;
}

// https://www.acmicpc.net/problem/1700