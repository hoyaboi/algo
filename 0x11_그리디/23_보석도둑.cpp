#include <bits/stdc++.h>
using namespace std;
#define W first
#define V second
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<pii> gem(n);
    vector<int> bag(k);
    for(auto& a : gem) cin >> a.W >> a.V;
    for(int& i : bag) cin >> i;
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    multiset<int> value;
    long long sum = 0;
    int j = 0;
    for(int i : bag) {
        while(j < n && gem[j].W <= i)
            value.insert(gem[j++].V);
        if(!value.empty()) {
            sum += *value.rbegin();
            value.erase(value.find(*value.rbegin()));
        }
    }

    cout << sum;
}

// https://www.acmicpc.net/problem/1202