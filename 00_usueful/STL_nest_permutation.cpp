#include <bits/stdc++.h>
using namespace std;

int arr[5], ans[5];

void func(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 순열 -> 123/132/213/231/312/321/
    int a[3] = {1, 2, 3};   
    do {
        for(int i = 0; i < 3; i++) cout << a[i];
        cout << "/";
    } while(next_permutation(a, a+3));
    cout << "\n";

    // 5C3 조합 -> 123/124/125/134/135/145/234/235/245/345/
    int b[5] = {0, 0, 0, 1, 1}; 
    do {
        for(int i = 0; i < 5; i++)
            if(b[i] == 0) cout << i + 1;
        cout << "/";
    } while(next_permutation(b, b+5));
    cout << "\n";

    // 백트래킹으로 구현한 조합 -> 위의 5C3결과와 동일
    for(int i = 0; i < 5; i++) arr[i] = i+1;
    func(0, 0);
    cout << "\n";
}
void func(int k, int start) {
    if(k == 3) {
        for(int i = 0; i < 3; i++) cout << ans[i];
        cout << "/";
        return;
    }
    for(int i = start; i < 5; i++) {
        ans[k] = i+1;
        func(k+1, i+1);
    }
}