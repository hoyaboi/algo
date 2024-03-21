#include <bits/stdc++.h>
using namespace std;
#define W first 
#define V second

int D[102][100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> bag(n);
    for(auto& a : bag) cin >> a.W >> a.V;
    sort(bag.begin(), bag.end());

    for(int i = 1; i <= n; i++) {
        int weight = bag[i-1].W, value = bag[i-1].V;
        for(int j = 0; j <= k; j++) {
            if(j < weight) D[i][j] = D[i-1][j];
            else D[i][j] = max(D[i-1][j], D[i-1][j-weight] + value);
        }
    }
    cout << D[n][k];
}

// https://www.acmicpc.net/problem/12865