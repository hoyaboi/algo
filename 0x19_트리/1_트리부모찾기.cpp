#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int parent[100002];

void DFS(int);
void BFS(int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS(1);
    for(int i = 2; i <= n; i++) cout << parent[i] << "\n";
}
void DFS(int node) {
    for(int child : adj[node]) {
        if(parent[node] == child) continue;
        parent[child] = node;
        DFS(child);
    }
}
void BFS(int node) {
    queue<int> que;
    que.push(node);

    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(int child : adj[cur]) {
            if(parent[cur] == child) continue;
            parent[child] = cur;
            que.push(child);
        }
    }
}

// https://www.acmicpc.net/problem/11725