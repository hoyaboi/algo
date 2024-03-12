#include <bits/stdc++.h>
using namespace std;

pair<int, int> R[1500002];
int D[1500002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> R[i].first >> R[i].second;
    
    for(int i = n; i > 0; i--) {
        if(i + R[i].first-1 > n) {
            D[i] = D[i+1];
            continue;
        }
        D[i] = max(D[i + R[i].first] + R[i].second, D[i+1]);
    }
    cout << D[1];
}


// https://www.acmicpc.net/problem/15486