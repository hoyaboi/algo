#include <bits/stdc++.h>
using namespace std;

int Y(int);
int M(int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum_Y = 0, sum_M = 0;
    cin >> n;
    vector<int> time(n);
    for(int i = 0; i < n; i++) {
        cin >> time[i];
        sum_Y += Y(time[i]);
        sum_M += M(time[i]);
    }
    if(sum_Y < sum_M) cout << "Y " << sum_Y;
    else if(sum_Y > sum_M) cout << "M " << sum_M;
    else cout << "Y M " << sum_M;
    cout << endl << endl << sum_Y << " " << sum_M << endl;
}
int Y(int time) {
    return ((time/30)+1)*10;
}
int M(int time) {
    return ((time/60)+1)*15;
}

// https://www.acmicpc.net/problem/1267