#include <bits/stdc++.h>
using namespace std;

int R[2][100002];
int D[100002][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < n; j++) {
                cin >> R[i][j];
                if(j < 1) D[j][i+1] = R[i][j];
            }
        for(int i = 1; i < n; i++) {
            D[i][0] = max(D[i-1][1], D[i-1][2]);
            D[i][1] = max(D[i-1][0], D[i-1][2]) + R[0][i];
            D[i][2] = max(D[i-1][0], D[i-1][1]) + R[1][i];
        }
        cout << *max_element(D[n-1], D[n-1] + 3) << "\n";
    }
}

// https://www.acmicpc.net/problem/9465