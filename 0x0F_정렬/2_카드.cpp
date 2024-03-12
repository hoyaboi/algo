#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    long long arr[100002] = {};
    int index = 0, cnt = 1, mxcnt = 0;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    long long tmp = arr[0];
    for(int i = 1; i < n; i++) {
        if(tmp == arr[i]) {
            cnt++;
            if(cnt > mxcnt) {
                index = i;
                mxcnt = cnt;
            }
            continue;
        }
        cnt = 1;
        tmp = arr[i];
    }
    cout << arr[index];
}

// https://www.acmicpc.net/problem/11652