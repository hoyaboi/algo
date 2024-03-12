#include <bits/stdc++.h>
using namespace std;

bool compare(int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // sort는 stable sort가 아님
    // stable sort 성질이 필요하면
    // stable_sort 사용!!


    // 좌표나 여러 속성이 있는 자료를 정렬할 때 pair나 tuple 사용하여 정렬!!!


    // 5로 나눈 나머지가 작은 순으로 정렬
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    sort(arr, arr+7, compare);
    for(int i : arr) cout << i << " ";
    cout << "\n";
    
}
bool compare(int a, int b) {
    if(a%5 != b%5) return a%5 < b%5;
    return a < b;
}