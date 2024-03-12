#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> L = {1, 2};               // {1, 2}
    list<int>::iterator it = L.begin(); // it는 1을 가리키고 있음

    // push_front()
    L.push_front(10);                   // {10, 1, 2}
    cout << *it << "\n";                // 1 출력
    for(auto it : L) cout << it << " "; // c++ 11 이상부터 지원
    cout << "\n";
    for(list<int>::iterator it = L.begin(); it != L.end(); it++)    // C++ 11 미만
        cout << *it << " ";
    cout << "\n";

    // push_back()
    L.push_back(20);                    // {10, 1, 2, 20}
    for(auto it : L) cout << it << " ";
    cout << "\n";

    // insert()
    L.insert(it++, 30);                 // it가 가리키는 곳(1)에 30 삽입 {10, 30, 1, 2, 20}
    for(auto it : L) cout << it << " ";
    cout << "\n";

    // erase()
    L.erase(prev(it));                        // it가 가리키는 곳(2) 제거 {10, 30, 1, 20}
    for(auto it : L) cout << it << " ";
    cout << "\n";
}
