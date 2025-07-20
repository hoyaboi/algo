#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int>> prque1;  // 30 20 10 출력
    // priority_queue<int> prque1; 와 동일
    prque1.push(20);
    prque1.push(10);
    prque1.push(30);
    while(!prque1.empty()) {
        cout << prque1.top() << " ";
        prque1.pop();
    }
    cout << "\n";

    priority_queue<int, vector<int>, greater<int>> prque2;  // 10 20 30 출력
    prque2.push(20);
    prque2.push(10);
    prque2.push(30);
    while(!prque2.empty()) {
        cout << prque2.top() << " ";
        prque2.pop();
    }
    cout << "\n";
}