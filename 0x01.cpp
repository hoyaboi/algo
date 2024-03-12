#include <bits/stdc++.h>
using namespace std;
int func1(int);
int func2(int[], int);
int func3(int);
int func4(int);
bool compare(int, int);

int main() {
    // 3의 배수와 5의 배수의 합
    cout << func1(34567) << ", ";
    cout << func1(27639) << endl;

    // 가장 큰 두 수의 합이 100을 넘는지
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};
    cout << func2(arr1, 3) << ", ";
    cout << func2(arr2, 2) << ", ";
    cout << func2(arr3, 4) << endl;

    // 제곱수인지
    cout << func3(9) << ", ";
    cout << func3(693953651) << ", ";
    cout << func3(756580036) << endl;

    // N이하의 수 중에서 가장 큰 2의 거듭제곱수 반환
    cout << func4(5) << ", ";
    cout << func4(97615282) << ", ";
    cout << func4(1024) << endl;
}

int func1(int N) {
    int sum = 0;
    for(int i = 0 ; i <= N; i++) {
        if(i % 3 == 0 || i % 5 == 0) sum += i;
    }
    return sum;
}
int func2(int arr[], int n) {
    // for(int i = 0; i < n-1; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         if(arr[i] < arr[j]) {
    //             int tmp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = tmp;
    //         }
    //     }
    // }
    sort(arr, arr + n, compare);
    if(arr[0] + arr[1] >= 100) return 1;
    return 0;
}
int func3(int N) {
    for(int i = 1; i * i <= N; i++) {
        if(i * i == N) return 1;
    }
    return 0;
}
int func4(int N) {
    int max = 1;
    while(max*2 <= N) max *= 2;
    return max;
}
bool compare(int a, int b) {
    return a > b;
}
