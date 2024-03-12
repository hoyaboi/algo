#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> height(9);
    int sum = 0;

    for(int i = 0; i < height.size(); i++) {
        cin >> height[i];
        sum += height[i];
    }
    sort(height.begin(), height.end());
    bool found = false;
    for(int i = 0; i < height.size() - 1; i++) {
        for(int j = i+1; j < height.size(); j++) {
            if(sum - (height[i] + height[j]) == 100) {
                height.erase(height.begin() + j);
                height.erase(height.begin() + i);
                found = true;
                break;
            }
        }
        if(found) break;
    }
    for(int i = 0; i < height.size(); i++) {
        cout << height[i] << "\n";
    }
}

// https://www.acmicpc.net/problem/2309