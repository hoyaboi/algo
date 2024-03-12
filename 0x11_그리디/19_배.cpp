#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> cranes(n);
    for(int& crane : cranes) cin >> crane;
    sort(cranes.rbegin(), cranes.rend());

    int m; cin >> m;
    vector<int> boxes(m);
    for(int& box : boxes) cin >> box;
    sort(boxes.rbegin(), boxes.rend());

    if(boxes[0] > cranes[0]) {
        cout << -1;
        return 0;
    }

    int days = 0;
    while(!boxes.empty()) {
        int i = 0;
        for(int j = 0; i < n && j < boxes.size(); j++) {
            if(cranes[i] >= boxes[j]) {
                boxes.erase(boxes.begin() + j);
                j--; i++;
            }
        }
        days++;
    }

    cout << days;
    return 0;
}


// https://www.acmicpc.net/problem/1092