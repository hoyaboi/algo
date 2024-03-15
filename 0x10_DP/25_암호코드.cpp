#include <bits/stdc++.h>
using namespace std;

long long D[5002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num; cin >> num;
    if(num[0] == '0') {
        cout << 0;
        return 0;
    }
    D[0] = D[1] = 1;
    for(int i = 2; i <= num.size(); i++) {
        int before = num[i-2]-'0', cur = num[i-1]-'0';
        int number = before * 10 + cur;

        if(cur > 0) D[i] = D[i-1];
        if(number >= 10 && number <= 26) D[i] = (D[i] + D[i-2]) % 1000000;
    }
    cout << D[num.size()];
}

// https://www.acmicpc.net/problem/2011