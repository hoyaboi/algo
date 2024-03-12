#include <bits/stdc++.h>
using namespace std;

bool img[65][65];

void cap(int, int, int);
bool check(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < tmp.length(); j++)
            img[i][j] = tmp[j] - '0';
    }
    cap(0, 0, n);
}
void cap(int x, int y, int n) {
    if(check(x, y, n)) {
        cout << img[x][y];
        return;
    }
    int subN = n/2;
    cout << "(";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cap(x + i*subN, y + j*subN, subN);
    cout << ")";
}
bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
        for(int j = y; j < y+n; j++)
            if(img[x][y] != img[i][j]) return false;
    return true;
}

// https://www.acmicpc.net/problem/1992