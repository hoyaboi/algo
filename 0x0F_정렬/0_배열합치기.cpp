#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> arr[3];

    arr[0].resize(n);
    arr[1].resize(m);
    arr[2].resize(n + m);

    for(int i = 0; i < n; i++) cin >> arr[0][i];
    for(int i = 0; i < m; i++) cin >> arr[1][i];

    // merge(arr[0].begin(), arr[0].end(), arr[1].begin(), arr[1].end(), arr[2].begin());

    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < n + m; i++) {
        if(idx1 == n) arr[2][i] = arr[1][idx2++];
        else if(idx2 == m) arr[2][i] = arr[0][idx1++];
        else if(arr[0][idx1] > arr[1][idx2]) arr[2][i] = arr[1][idx2++];
        else arr[2][i] = arr[0][idx1++];
    }

    for(int i : arr[2]) cout << i << " ";
}

// https://www.acmicpc.net/problem/11728