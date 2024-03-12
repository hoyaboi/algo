#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num(5);
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        cin >> num[i];
        sum += num[i];
    }
    sort(num.begin(), num.end());
    cout << sum / 5 << "\n" << num[2];
}

// https://www.acmicpc.net/problem/2587