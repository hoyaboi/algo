#include <bits/stdc++.h>
using namespace std;

int cnt, n;
int col[15];

void queens(int);
bool promising(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queens(0);
    cout << cnt;
}
void queens(int k) {
    if(promising(k)) {
        if(k == n) {
            cnt++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            col[k+1] = i;
            queens(k+1);
        }
    }
}
bool promising(int k) {
    for(int i = 1; i < k; i++)
        if(col[i] == col[k] || abs(col[k] - col[i]) == abs(k-i)) return false;
    return true;
}

// https://www.acmicpc.net/problem/9663