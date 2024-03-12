#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input(7);
    vector<int> odd;
    int count = 0;

    for(int i = 0; i < 7; i++) {
        cin >> input[i];
        if(input[i] % 2 != 0) {
            count++;
            odd.push_back(input[i]);
        }
    }
    if(count == 0) {
        cout << -1;
        return 0;
    } else {
        int sum = 0;
        sort(odd.begin(), odd.end());
        for(int i = 0; i < odd.size(); i++) {
            sum += odd[i];
        }
        cout << sum << "\n" << odd[0];
    }
}

// https://www.acmicpc.net/problem/2576