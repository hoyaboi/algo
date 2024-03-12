#include <bits/stdc++.h>
using namespace std;

// 이진 탐색

int binarySearch(vector<int>&, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> A(n), B(m);
        for(int& i : A) cin >> i;
        for(int& i : B) cin >> i;
        sort(B.begin(), B.end());

        int cnt = 0;
        for(int i : A) cnt += binarySearch(B, i);
        // for(int i : A) cnt += upper_bound(B.begin(), B.end(), i) - B.begin();
        cout << cnt << "\n";
    }
}
int binarySearch(vector<int>& B, int k) {
    int left = 0, right = B.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(B[mid] < k) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// https://www.acmicpc.net/problem/7795