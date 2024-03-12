#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, A[5][5];
ll b;

void matrix(int[][5], ll);
void matrix_mul(int[][5], int[][5], int[][5]);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    matrix(A, b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}
void matrix(int result[][5], ll num) {
    if(num == 1) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                result[i][j] = A[i][j];
        return;
    }
    if(num % 2 == 0) {
        int tmp[5][5] = {0};
        matrix(tmp, num/2);
        matrix_mul(tmp, tmp, result);
        return;
    }
    int tmp1[5][5] = {0}, tmp2[5][5] = {0};
    matrix(tmp1, num/2);
    matrix(tmp2, num-num/2);
    matrix_mul(tmp1, tmp2, result);
    return;
}
void matrix_mul(int A[][5], int B[][5], int result[][5]) {
    for(int i = 0 ; i < n; i++) fill(result[i], result[i] + n, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= 1000;
            }
}


// https://www.acmicpc.net/problem/10830