#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    vector<int> D, R, sub;
    vector<char> C;
    int tmp = 0;
    for(char c : str) {
        if(c == '+' || c == '-') {
            C.push_back(c);
            D.push_back(tmp);
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += c-'0';
        }
    }
    D.push_back(tmp);

    for(int i = 0; i < D.size(); i++) {
        if(C[i-1] == '-') {
            R.push_back(sum(sub));
            sub.clear();
        }
        sub.push_back(D[i]);
    }
    if(!sub.empty()) R.push_back(sum(sub));

    int ans = R[0];
    for(int i = 1; i < R.size(); i++) ans -= R[i];
    cout << ans;
}
int sum(vector<int> tmp) {
    int sum = 0;
    for(int i : tmp) sum += i;
    return sum;
}

// https://www.acmicpc.net/problem/1541