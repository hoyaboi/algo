#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> str1(26);
    vector<int> str2(26);
    int count = 0;
    string tmp1, tmp2;

    cin >> tmp1 >> tmp2;
    for(char c : tmp1) str1[c-'a']++;
    for(char c : tmp2) str2[c-'a']++;

    for(int i = 0; i < str1.size(); i++)
        count += abs(str1[i] - str2[i]);

    cout << count;
}

// https://www.acmicpc.net/problem/1919