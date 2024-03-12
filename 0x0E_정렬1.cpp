#include <bits/stdc++.h>
using namespace std;

void mergesort(int, int, int*);
void merge(int, int, int*, int*, int*);

void printArr(int*, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // merge sort -> stable sort 성질을 가지고 있음
    int* arr1 = new int[10];
    int tmp[10] = {3, 5, 1, 2, 6, 4, 10, 7, 9, 8};
    for (int i = 0; i < 10; i++) arr1[i] = tmp[i];
    mergesort(3, 8, arr1);
    printArr(arr1, 10);

    // quick sort


}
void mergesort(int start, int end, int* arr) {
    if(start < end) {
        int mid = (start + end)/2;
        int h = mid - start + 1;
        int m = end - mid;
        int* subLeft = new int[h];
        int* subRight = new int[m];

        copy(arr + start, arr + mid + 1, subLeft);
        copy(arr + mid + 1, arr + end + 1, subRight);

        mergesort(0, h-1, subLeft);
        mergesort(0, m-1, subRight);
        merge(h, m, subLeft, subRight, arr + start);

        delete[] subLeft;
        delete[] subRight;
    }
}
void merge(int h, int m, int* left, int* right, int* dest) {
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < h + m; i++) {
        if(idx1 == h) dest[i] = right[idx2++];
        else if(idx2 == m) dest[i] = left[idx1++];
        else if(left[idx1] > right[idx2]) dest[i] = right[idx2++];
        else dest[i] = left[idx1++];
     }
}


void printArr(int* arr, int size) {
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}