#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<tuple<int, int, int, string>> std;
    while(n--) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        std.push_back({-kor, eng, -math, name});
    }
    sort(std.begin(), std.end());
    for(auto& i : std)
        cout << get<3>(i) << "\n";
}

// https://www.acmicpc.net/problem/10825