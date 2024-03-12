#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. atoi
    string str = "123";
    int num = atoi(str.c_str());
    cout << num << "\n";

    // 2. stoi
    str = "456";
    num = stoi(str);
    cout << num << "\n";

    // reverse
    str = "12345";
    reverse(str.begin(), str.end());
    num = stoi(str);
    cout << num << "\n";

    // 문자열 중 정수만 고르기
    str = "AB3C57";
    int sum = 0;
    for(auto i : str) if(isdigit(i)) sum += (i - '0');
    cout << sum << "\n";
}