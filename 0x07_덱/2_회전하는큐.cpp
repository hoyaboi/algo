#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, count = 0;
    cin >> n >> m;
    deque<int> deq;
    vector<int> index(m);

    for(int i = 1; i <= n; i++) deq.push_back(i);
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        index[i] = tmp-1;
    }

    int i = 0;
    while(i < m) {
        if(index[i] == 0) {
            deq.pop_front();
            for(int j = i; j < m; j++) index[j]--;
            i++;
            continue;
        }
        if(index[i] <= deq.size()-index[i]) {         
            deq.push_back(deq.front());
            deq.pop_front();
            for(int j = i; j < m; j++) index[j] = (index[j] + deq.size() - 1) % deq.size();
        } else {
            deq.push_front(deq.back());
            deq.pop_back();
            for(int j = i; j < m; j++) index[j] = (index[j] + 1) % deq.size();
        }
        count++;
    }
    cout << count;
}

// https://www.acmicpc.net/problem/1021