#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int vis[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    queue<int> que;
    vis[n] = 1;
    que.push(n);
    
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt < 0 || nxt > 100000 || vis[nxt]) continue;
            vis[nxt] = vis[cur] + 1;
            que.push(nxt);
        }
    }
    cout << vis[k]-1;
}

// https://www.acmicpc.net/problem/1697