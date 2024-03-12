#include <bits/stdc++.h>
using namespace std;

void insert(int, int, int[], int&);
void erase(int, int[], int&);
void printArr(int[], int&);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;

    insert(3, 60, arr, len);
    printArr(arr, len);

    erase(4, arr, len);
    printArr(arr, len);

}

void insert(int index, int num, int arr[], int &len) {
    for(int i = len; i > index; i--)
        arr[i] = arr[i-1];
    arr[index] = num;
    len++;
}
void erase(int index, int arr[], int &len) {
    for(int i = index+1; i < len; i++)
        arr[i-1] = arr[i];
    len--;
}
void printArr(int arr[], int &len) {
    for(int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}