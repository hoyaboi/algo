#include <bits/stdc++.h>
using namespace std;

bool compare(string&, string&);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> arr;
    while(n--) {
        bool same = false;
        string tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), compare);
    string tmp = "";
    for(auto i : arr) {
        if(tmp == i) continue;
        tmp = i;
        cout << i << "\n";
    }
}
bool compare(string& str1, string& str2) {
    if(str1.size() != str2.size()) return str1.size() < str2.size();
    return str1 < str2;
}

// https://www.acmicpc.net/problem/1181