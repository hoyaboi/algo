#include <bits/stdc++.h>
using namespace std;

int func(vector<int>);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr1 = {1, 52, 48};
    vector<int> arr2 = {50, 42};
    vector<int> arr3 = {4, 13, 63, 87};

    cout << func(arr1) << ", ";
    cout << func(arr2) << ", ";
    cout << func(arr3) << "\n";
}
int func(vector<int> arr) {
    vector<bool> check(101);
    for(int i = 0; i < arr.size(); i++) {
        if(check[100-arr[i]]) return 1;
        check[arr[i]] = true;
    }
    return 0;
}