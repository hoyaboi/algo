#include <bits/stdc++.h>
using namespace std;

bool arr[100002];

bool isPrime(int);
void fastPrime(int, int);
int GCD(int, int);
int LCM(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 소수 판별 : isPrime() 함수

    // 범위 내의 소수 출력 : fastPrime() 함수
    fastPrime(4, 20); cout << "\n";

    // 최대공약수 : 유클리드 호제법 이용 => GCD(a, b) 이용
    // 12와 20의 최대공약수 : GCD(20, 12) = GCD(12, 8) = GCD(8, 4) = GCD(4, 0) = 0
    cout << GCD(20, 12); cout << "\n";

    // 최소공배수 : LCM(A, B) 이용 -> A X B = GCD(A, B) X LCM(A, B)
    cout << LCM(20, 12); cout << "\n";

    // 연립합동방정식
    // 6명씩 조를 짜면 3명이 남고, 5명씩 조를 짜면 2명이 남는다. 전체 학생 수는 30명 미만
    int n = 0;
    for(int i = 3; i <= 30; i += 6)
        if(i % 5 == 2) n = i;
    
    // 이항계수
    // 이항 정리를 이용한 DP로 해결 : nCk = n-1Ck-1 + n-1Ck
}
bool isPrime(int n) {
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}
void fastPrime(int start, int end) {
    for(int i = 2; i <= end; i++) {
        if(arr[i]) continue;
        if(i >= start) cout << i << ", ";
        for(int j = i * i; j <= end; j += i)
            arr[j] = 1;
    }
}
int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}
int LCM(int a, int b) {
    return a / GCD(a, b) * b;   // (a * b) / GCD(a, b) 로 안 한 이유 : int overflow 방지
}

