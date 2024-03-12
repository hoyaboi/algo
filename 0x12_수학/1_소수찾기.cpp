#include <bits/stdc++.h>
using namespace std;

bool isPrime(int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n; cin >> m >> n;
    for(int i = m; i <= n; i++)
        if(isPrime(i)) cout << i << "\n";

}
bool isPrime(int n) {
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++) 
        if(n % i == 0) return 0;
    return 1;
}

// https://www.acmicpc.net/problem/1978