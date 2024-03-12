#include <bits/stdc++.h>
using namespace std;
#define COUNT 1000000

int num_arr[10];

int count_num(int, int);
int main() {
    srand(time(0));
    // 1
    for(int i = 0; i < COUNT; i++) {
        int num = rand() % 10000; 
        string str_num = to_string(num);
        for(int j = 0; j < str_num.length(); j++) {
            num_arr[str_num[j]-'0']++;
        }
    }

    //2
    // for(int i = 0; i < COUNT; i++) {
    //     int num = rand() % 10;
    //     num_arr[num]++;
    // }

    for(int i = 0; i < 10; i++)
        cout << i << ": " << num_arr[i] << " / ";

    cout << "\n0 ~ 9 ->\t";
    count_num(0, 9);
    cout << "10 ~ 99 ->\t";
    count_num(10, 99);
    cout << "100 ~ 999 ->\t";
    count_num(100, 999);
    cout << "1000 ~ 9999 ->\t";
    count_num(1000, 9999);
}
int count_num(int start, int end) {
    fill(num_arr, num_arr + 10, 0);
    for(int i = start; i <= end; i++) {
        string tmp = to_string(i);
        for(char c : tmp) num_arr[c-'0']++;
    }
    for(int i = 0; i < 10; i++) printf("%d: %-5d / ", i, num_arr[i]);
    cout << "\n";
}