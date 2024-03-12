#include <bits/stdc++.h>
using namespace std;

int R[1002], DL[1002], DR[1002], D[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> R[i];
    fill(DL, DL + n, 1);
    fill(DR, DR + n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++)
            if(R[i] > R[j]) DL[i] = max(DL[i], DL[j] + 1);
        for(int j = n-1; j > n-i-1; j--)
            if(R[n-i-1] > R[j]) DR[n-i-1] = max(DR[n-i-1], DR[j] + 1);
    }
    for(int i = 0; i < n; i++)
        D[i] = DL[i] + DR[i] - 1;
    cout << *max_element(D, D + n);
}


// https://www.acmicpc.net/problem/11054