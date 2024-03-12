#include <bits/stdc++.h>
using namespace std;

bool compare(string&, string&);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> arr;
    while(n--) {
        string tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), compare);
    for(string str : arr) cout << str << "\n";
}
bool compare(string& str1, string& str2) {
    int len1 = str1.size(), len2 = str2.size();
    int sum1 = 0, sum2 = 0;

    if(len1 != len2) return len1 < len2;

    for(auto i : str1) if(isdigit(i)) sum1 += (i - '0');
    for(auto i : str2) if(isdigit(i)) sum2 += (i - '0');
    if(sum1 != sum2) return sum1 < sum2;

    return str1 < str2;
}

// https://www.acmicpc.net/problem/1431