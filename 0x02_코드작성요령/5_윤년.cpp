#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;

    cout << ((year%4==0)&&((year%100!=0)||(year%400==0)))?1:0;

}

// https://www.acmicpc.net/problem/2753
