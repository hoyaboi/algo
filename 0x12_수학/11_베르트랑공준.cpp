#include <bits/stdc++.h>
using namespace std;
#define SIZE 250000

bool prime[SIZE];
int count(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(prime, prime + SIZE, 1);
    for(int i = 2; i < SIZE; i++) {
        if(!prime[i]) continue;
        for(int j = 2*i; j < SIZE; j += i)
            prime[j] = 0;
    }

    while(1) {
        int n; cin >> n;
        if(n == 0) return 0;
        cout << count(n, 2*n) << "\n";
    }
}
int count(int s, int e) {
    int cnt = 0;
    for(int i = s+1; i <= e; i++)
        if(prime[i]) cnt++;
    return cnt;
}

// https://www.acmicpc.net/problem/4948