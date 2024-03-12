#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num(3);
    int price;

    for(int i = 0; i < 3; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    if(num[0] == num[2]) price = 10000 + num[0]*1000;
    else if(num[0] == num[1] || num[1] == num[2]) price = 1000 + num[1]*100;
    else price = num[2]*100;
    cout << price;
}

// https://www.acmicpc.net/problem/2480