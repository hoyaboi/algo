#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, sum, count = 0;
    cin >> num;
    vector<bool> num_arr(1000001);

    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        num_arr[tmp] = true;
    }
    cin >> sum;

    for(int i = 0; i < 15; i++) cout << num_arr[i] << " ";
    cout << "\n";
    
    for(int i = 1; i < (sum+1)/2; i++)
        if(num_arr[i] && num_arr[sum-i]) count++;

    
    cout << count;
}

// https://www.acmicpc.net/problem/1475