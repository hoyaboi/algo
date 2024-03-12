#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> count(26);
    
    for(int i = 0; i < s.size(); i++)
        count[s[i] % 97]++;
    for(int i : count) cout << i << " ";
}

// https://www.acmicpc.net/problem/10808