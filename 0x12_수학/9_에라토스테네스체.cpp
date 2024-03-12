#include <bits/stdc++.h>
using namespace std;

bool isUsed[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            if(isUsed[j]) continue;
            isUsed[j] = true;
            cnt++;
            if(cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}

// https://www.acmicpc.net/problem/2960