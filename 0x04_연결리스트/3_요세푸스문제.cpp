#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, gap, pos = 1;
    cin >> num >> gap;
    vector<int> data(num+1), next(num+1), prev(num+1);

    for(int i = 1; i <= num; i++) {
        data[i] = i;
        next[i] = (i == num)? 1: i+1;
        prev[i] = (i == 1)? num: i-1;
    }

    cout << "<";
    for(int i = 0; i < num; i++) {
        for(int i = 1; i < gap; i++) pos = next[pos];
        cout << data[pos];
        if(i != num-1) cout << ", ";
        prev[next[pos]] = prev[pos];
        next[prev[pos]] = next[pos];
        pos = next[pos];
    }
    cout << ">";
}

// https://www.acmicpc.net/problem/1158