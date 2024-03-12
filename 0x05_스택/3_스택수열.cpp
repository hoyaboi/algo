#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool isPossible = true;
    int n, pos = 1;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    stack<int> stk;
    string result = "";

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] > arr[i-1]) {
            for(pos; pos <= arr[i]; pos++) {
                stk.push(pos);
                result += "+\n";
            }
            stk.pop();
            result += "-\n";
        } else {
            if(stk.top() == arr[i]) {
                stk.pop();
                result += "-\n";
            } else isPossible = false;
        }
    }
    if(isPossible) cout << result;
    else cout << "NO";
}

// https://www.acmicpc.net/problem/1874