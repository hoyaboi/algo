#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

void back(int);
bool promising();

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    back(0);
}
void back(int k) {
    if(k == n) {
        for(int i : ans) cout << i;
        exit(0);
    }
    for(int i = 1; i <= 3; i++) {
        ans.push_back(i);
        if(promising()) back(k+1);
        ans.pop_back();
    }
}
bool promising() {
    int len = ans.size();
    for(int i = 1; i <= len/2; i++) {
        bool valid = true;
        for(int j = 0; j < i; j++)
            if(ans[len-j-1] != ans[len-j-i-1]) {
                valid = false;
                break;
            }
        if(valid) return false;
    }
    return true;
}

// https://www.acmicpc.net/problem/2661