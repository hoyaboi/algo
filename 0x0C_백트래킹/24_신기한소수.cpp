#include <bits/stdc++.h>
using namespace std;

int n, prime;

bool isPrime(int);
void back(int);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    back(0);
}
bool isPrime(int k) {
    if(k == 1) return 0;
    for(int i = 2; i*i <= k; i++)
        if(k % i == 0) return 0;
    return 1;
}
void back(int k) {
    if(k == n) {
        if(isPrime(prime)) cout << prime << "\n";
        return;
    }
    for(int i = 1; i < 10; i++) {
        if(k == 0) prime = i;
        else prime = prime*10 + i;
        if(isPrime(prime)) back(k+1);
        prime /= 10;
    }
}

// https://www.acmicpc.net/problem/2023