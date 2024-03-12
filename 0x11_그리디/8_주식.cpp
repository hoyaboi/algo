#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> stock(n);
        for(int& i : stock) cin >> i;
        int pivot = n-1;
        long long profit = 0;
        for(int i = n-2; i >= 0; i--) {
            if(stock[pivot] <= stock[i]) pivot = i;
            else profit += stock[pivot] - stock[i];
        }
        cout << profit << "\n";
    }
}

// https://www.acmicpc.net/problem/11501