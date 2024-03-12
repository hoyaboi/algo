#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[21];

void func(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--;
    cout << cnt;
}
void func(int k, int sum) {
    if(k == n) {
        if(sum == s) cnt++;
        return;
    }
    func(k+1, sum + arr[k]);
    func(k+1, sum);
}


// https://www.acmicpc.net/problem/1182