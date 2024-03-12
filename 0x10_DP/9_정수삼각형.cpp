#include <bits/stdc++.h>
using namespace std;

int D[502][502], R[502][502];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) {
            cin >> R[i][j];
            if(j == 0) {
                if(i == 0) D[i][j] = R[i][j];
                else D[i][j] = D[i-1][j] + R[i][j];
            }
        }
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= i; j++)
            D[i][j] = max(D[i-1][j-1], D[i-1][j]) + R[i][j];
            
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, D[n-1][i]);
    cout << ans << "\n";
}

// https://www.acmicpc.net/problem/1932