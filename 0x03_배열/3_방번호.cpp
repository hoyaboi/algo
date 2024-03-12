#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, set = 1;
    vector<int> count(9);

    cin >> num;
    string num_str = to_string(num);
    for(int i = 0; i < num_str.size(); i++) {
        int index = num_str[i] - '0';
        if(index == 6 || index == 9) {
            count[6]++;
            if((count[6]+1)/2 > set) set = (count[6]+1)/2;
        }
        else {
            count[index]++;
            if(count[index] > set) set = count[index];
        }
    }

    cout << set;
}

// https://www.acmicpc.net/problem/1475