#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score;
    cin >> score;

    switch(score / 10) {
    case 10: case 9:
        cout << "A"; break;
    case 8:
        cout << "B"; break;
    case 7: 
        cout << "C"; break;
    case 6:
        cout << "D"; break;
    default:
        cout << "F";
    }
}

// https://www.acmicpc.net/problem/9498