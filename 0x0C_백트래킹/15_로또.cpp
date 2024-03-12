#include <bits/stdc++.h>
using namespace std;

int arr[50], lot[6], k;

void func(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> arr[i];
        func(0, 0);
        cout << "\n";
    }
}
void func(int n, int start) {
    if(n == 6) {
        for(int i = 0; i < 6; i++) cout << lot[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = start; i < k; i++) {
        lot[n] = arr[i];
        func(n+1, i+1);
    }
}

// https://www.acmicpc.net/problem/6603