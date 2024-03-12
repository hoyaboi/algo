#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> words(n);
    map<char, int> weight;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        int len = words[i].length();
        for (int j = 0; j < len; j++) {
            char c = words[i][j];
            weight[c] += pow(10, len - j - 1);
        }
    }

    vector<pair<int, char>> weightList;
    for(auto& it : weight) weightList.push_back({it.second, it.first});

    sort(weightList.rbegin(), weightList.rend());

    int assign = 9, totalSum = 0;
    map<char, int> charToNum;
    for(auto& it : weightList) charToNum[it.second] = assign--;

    for (auto& word : words) {
        int currentNum = 0;
        for(char c : word) currentNum = currentNum * 10 + charToNum[c];
        totalSum += currentNum;
    }

    cout << totalSum;
}

// https://www.acmicpc.net/problem/1339