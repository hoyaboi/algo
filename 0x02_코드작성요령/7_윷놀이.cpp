#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<vector<int>> vec(4, vector<int>(3));
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         cin >> vec[i][j];
    //     }
    // }
    // for(int i = 0; i < 3; i++) {
    //     int count = 0;
    //     for(int j = 0; j < 4; j++) {
    //         if(vec[i][j] == 0) count++;
    //     }
    //     if(count == 0) cout << "E";
    //     else if(count == 1) cout << "A";
    //     else if(count == 2) cout << "B";
    //     else if(count == 3) cout << "C";
    //     else cout << "D";
    //     cout << "\n";
    // }

    int result, input;
    string res = "DCBAE";

    for(int i = 0; i < 3; i++) {
        result = 0;
        for(int j = 0; j < 4; j++) {
            cin >> input;
            result += input;
        }
        cout << res[result] << "\n";
    }
}

// https://www.acmicpc.net/problem/2490