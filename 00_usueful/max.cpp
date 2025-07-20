#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[4] = {1, 2, 3};

    int M1 = max(arr[0], arr[1]);
    int M2 = max({arr[0], arr[1], arr[2]});
    cout << M1 << "\n";
    cout << M2 << "\n";

    int M = *max_element(arr, arr + 3);
    cout << M << "\n";
}
