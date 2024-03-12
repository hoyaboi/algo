#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    vector<int> count(10);

    cin >> a >> b >> c;
    int mul = a * b * c;

    while(mul) {
        count[mul%10]++;
        mul /= 10;
    }

    for(int i : count) cout << i << "\n";
}

// https://www.acmicpc.net/problem/2577