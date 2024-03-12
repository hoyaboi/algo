#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    tuple<int, int, int> tup;
    int a = 10, b = 20, c = 30;
    tup = {a, b, c};

    auto [p, q, r] = tup;
    cout << p << " " << q << " " << r << "\n";

    cout << get<0>(tup) << " ";
    cout << get<1>(tup) << " ";
    cout << get<2>(tup) << "\n";
}