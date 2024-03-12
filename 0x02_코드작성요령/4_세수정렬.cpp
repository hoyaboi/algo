#include <bits/stdc++.h>
#define N 3
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num_arr(N);
    for(int i = 0; i < N; i++) cin >> num_arr[i];
    sort(num_arr.begin(), num_arr.end());
    for(int i = 0; i < N; i++) cout << num_arr[i] << " ";
}

// https://www.acmicpc.net/problem/2752