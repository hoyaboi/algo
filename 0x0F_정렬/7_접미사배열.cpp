#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    vector<string> arr;

    for(int i = 0; i < str.size(); i++)
        arr.push_back(str.substr(i));
    sort(arr.begin(), arr.end());

    for(auto i : arr) cout << i << "\n";
}

// https://www.acmicpc.net/problem/11656