#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    vector<int> card(20);
    for(int i = 0; i < 20; i++) {
        card[i] = i + 1;
    }
    for(int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverse(card.begin() + a-1, card.begin() + b);
    }
    for(int i = 0; i < 20; i++) {
        cout << card[i] << " ";
    }
}

// https://www.acmicpc.net/problem/10804