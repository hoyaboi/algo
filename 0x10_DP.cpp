#include <bits/stdc++.h>
using namespace std;

int fib(int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 테이블 정의

    // 2. 점화식 찾기

    // 3. 초깃값 설정

    cout << fib(7) << "\n";
}
int fib(int n) {
    int fib[20];
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}

