#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, room = 0;
    cin >> n >> k;
    vector<int> sex(n);
    vector<int> grade(n);
    vector<vector<int>> count(2, vector<int>(7));

    for(int i = 0; i < n; i++)
        cin >> sex[i] >> grade[i];
    for(int i = 0; i < n; i++)
        count[sex[i]][grade[i]]++;
    for(vector<int> i : count) {
        for(int j : i) {
            if(j != 0) room += (j+k-1) / k;
            else continue;
        }
    }

    cout << room;
}

// https://www.acmicpc.net/problem/13300