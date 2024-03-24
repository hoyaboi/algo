#include <bits/stdc++.h>
using namespace std;

int GCD(int, int);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    while(n--) {
        int num, k; cin >> k;
        long long sum = 0;
        vector<int> vec(k);
        for(int &i : vec) cin >> i;
        for(int i = 0; i < vec.size()-1; i++) 
            for(int j = i+1; j < vec.size(); j++)
                sum += GCD(vec[i], vec[j]);
        cout << sum << "\n";
    }
}
int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}

// https://www.acmicpc.net/problem/9613