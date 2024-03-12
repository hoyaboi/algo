#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len, num;
    cin >> len;
    vector<int> count(201);

    for(int i = 1; i <= len; i++) {
        int tmp;
        cin >> tmp;
        count[tmp+100]++;
    }
    cin >> num;
    cout << count[num+100];
}

// https://www.acmicpc.net/problem/10807