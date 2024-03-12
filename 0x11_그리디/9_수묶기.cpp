#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> pos, neg;
    bool isZero = false;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp > 0) pos.push_back(tmp);
        else if(tmp < 0) neg.push_back(tmp);
        else isZero = true;
    }
    sort(pos.begin(), pos.end(), [](int a, int b) {return a > b;});
    sort(neg.begin(), neg.end());
    int ans = 0;
    for(int i = 1; i < pos.size(); i += 2) {
        if(pos[i] == 1) ans += pos[i] + pos[i-1];
        else ans += pos[i] * pos[i-1];
    }
    if(pos.size() % 2 != 0) ans += pos.back();
    for(int i = 1; i < neg.size(); i += 2)
        ans += neg[i] * neg[i-1];
    if(neg.size() % 2 != 0)
        if(!isZero) ans += neg.back();

    cout << ans;
}

// https://www.acmicpc.net/problem/1744