#include <bits/stdc++.h>
using namespace std;

int vis[1000002];
int f, s, g, u, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    queue<int> que;
    vis[s] = 1;
    que.push(s);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(auto dir : {cur + u, cur - d}) {
            if(dir > f || dir <= 0 || vis[dir]) continue;
            vis[dir] = vis[cur] + 1;
            que.push(dir);
        }
    }
    if(vis[g]) cout << vis[g]-1;
    else cout << "use the stairs";
}

// https://www.acmicpc.net/problem/5014