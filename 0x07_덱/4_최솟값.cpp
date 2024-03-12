#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    deque<pair<int, int>> deq;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while(!deq.empty() && deq.back().first >= num)
            deq.pop_back();
        
        deq.push_back({num, i});

        if(deq.front().second == i-l)
            deq.pop_front();

        cout << deq.front().first << " ";
    }
}

// https://www.acmicpc.net/problem/11003