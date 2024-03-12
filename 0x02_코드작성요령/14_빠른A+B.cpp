#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num1, num2;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num1 >> num2;
        cout << num1 + num2 << "\n";
    }
}

// https://www.acmicpc.net/problem/15552