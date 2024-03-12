#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int cnt[3];

bool check(int, int, int);
void func(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    
    func(0, 0, n);
    for(int i : cnt) cout << i << "\n";
}
void func(int x, int y, int n) {
    if(check(x, y, n)) {
        cnt[paper[x][y] + 1]++;
        return;
    }
    int subN = n / 3;
    for(int i = x; i < x + n; i+=subN)
        for(int j = y; j < y + n; j+=subN)
            func(i, j, subN);
}
bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(paper[x][y] != paper[i][j]) return false;
    return true;
}

// https://www.acmicpc.net/problem/1780