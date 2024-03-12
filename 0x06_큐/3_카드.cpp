#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> card;

    for(int i = 1; i <= n; i++) card.push(i);
    while(card.size() != 1) {
        int tmp;
        card.pop();
        tmp = card.front();
        card.pop();
        card.push(tmp);
    }
    cout << card.front();
}

// https://www.acmicpc.net/problem/2164