#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    string str; cin >> str;
    stack<int> num;
    queue<int> ans;
    for(int i = n-1; i >= 0; i--) num.push(str[i]-'0');
    int cnt = 0;
    while(!num.empty()) {
        if(cnt == k) break;
        if(num.size() == 1) {
            ans.push(num.top());
            num.pop();
            break;
        }
        int a = num.top(); num.pop();
        int b = num.top(); num.pop();
        if(a >= b) ans.push(a);
        else cnt++;
        num.push(b);
    }
    while(!num.empty()) {
        ans.push(num.top());
        num.pop();
    }
    while(!ans.empty()) {
        cout << ans.front();
        ans.pop();
    }
}