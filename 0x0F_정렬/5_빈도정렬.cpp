#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c; cin >> n >> c;
    vector<pair<int, bool>> arr;
    vector<pair<int, int>> cnt;
    while(n--) {
        int tmp; cin >> tmp;
        arr.push_back({tmp, 0});
    }
    for(int i = 0; i < arr.size(); i++) {
        int cnt_tmp = 1;
        if(!arr[i].second) {
            for(int j = i + 1; j < arr.size(); j++) {
                if(!arr[j].second && arr[i].first == arr[j].first) {
                    cnt_tmp++;
                    arr[j].second = 1;
                }
            }
            cnt.push_back({cnt_tmp, arr[i].first});
            arr[i].second = 1;
        }
    }
    stable_sort(cnt.begin(), cnt.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });
    for(auto i : cnt)
        for(int j = 0; j < i.first; j++) cout << i.second << " ";
}

// https://www.acmicpc.net/problem/2910