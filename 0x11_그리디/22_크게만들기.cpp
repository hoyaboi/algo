#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    string str; cin >> str;
    queue<int> num;
    deque<int> ans;
    for(char c : str) num.push(c-'0');
    int cnt = 0;
    while(!num.empty() && cnt < k) {
        int a = num.front(); num.pop();
        if(ans.empty()) {
            ans.push_back(a);
            continue;
        }
        while(!ans.empty() && ans.back() < a) {
            ans.pop_back();
            if(++cnt == k) break;
        }
        ans.push_back(a);
    }
    while(!num.empty()) {
        ans.push_back(num.front());
        num.pop();
    }
    while(!ans.empty() && n-k > 0) {
        cout << ans.front();
        ans.pop_front();
        n--;
    }
}

// https://www.acmicpc.net/problem/2812