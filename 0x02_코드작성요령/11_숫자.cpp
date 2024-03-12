#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long num1, num2;
    cin >> num1 >> num2;
    int gap = abs(num1-num2);
    if(gap == 0 || gap == 1) {
        cout << "0";
        return 0;
    }
    cout << gap - 1 << "\n";
    for(int i = 0; i < gap-1; i++) {
        if(num1 > num2) cout << num2 + i + 1 << " ";
        else cout << num1 + i + 1 << " ";
    }

}

// https://www.acmicpc.net/problem/10093