#include <bits/stdc++.h>
using namespace std;

string str[1000002];
vector<long long> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        reverse(str[i].begin(), str[i].end());
        arr.push_back(stoll(str[i]));
    }
    sort(arr.begin(), arr.end());
    for(long long i : arr) cout << i << "\n";
}

// https://www.acmicpc.net/problem/5648