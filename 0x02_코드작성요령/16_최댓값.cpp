#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input, max_num = 0, pos = 0;

    for(int i = 1; i < 10; i++) {
        cin >> input;
        if(input > max_num) {
            max_num = input;
            pos = i;
        }
    }
    cout << max_num << "\n" << pos;
}

// https://www.acmicpc.net/problem/2562