#include <bits/stdc++.h>
using namespace std;

int l, c; 
char R[16], D[16];

void func(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for(int i = 0; i < c; i++) cin >> R[i];
    sort(R, R + c);
    func(0, 0);
}
void func(int n, int start) {
    if(n == l) {
        int cntC = 0, cntV = 0;
        for(int i = 0; i < n; i++) {
            if(D[i] == 'a' || D[i] == 'e' || D[i] == 'i' || D[i] == 'o' || D[i] == 'u') cntV++;
            else cntC++;
        }
        if(cntC < 2 || cntV < 1) return;
        for(int i = 0; i < n; i++) cout << D[i];
        cout << "\n";
        return;
    }   
    for(int i = start; i < c; i++) {
        D[n] = R[i];
        func(n+1, i+1);
    }
}

// https://www.acmicpc.net/problem/1759